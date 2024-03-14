/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:57:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/14 13:34:27 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_monitor(t_philo_data *data, pthread_t monitor_thread)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_join(data->philos[i].philo, NULL) != 0)
		{
			//cleaner(data);
			exit_message("Join failure");
		}
	}
	if (pthread_join(monitor_thread, NULL) != 0)
	{
		//cleaner(data);
		exit_message("Monitor thread join failure");
	}
}

void	*monitor(void *arg)
{
	t_philo_data	*data;
	int				i;

	data = (t_philo_data *)arg;
	i = -1;
	while (1)
	{
		i = -1;
		while (++i < data->num_philos)
		{
			pthread_mutex_lock(&data->status_mutex);
			pthread_mutex_lock(&data->philos[i].protect_last);
			if (current_time() - data->philos[i].last_ate > data->time_to_die)
			{
				pthread_mutex_unlock(&data->philos[i].protect_last);
				printf("%ld %d died\n", current_time() - data->start_time,
						data->philos[i].id);
				data->philo_dead = true;
				pthread_mutex_unlock(&data->status_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philos[i].protect_last);
			pthread_mutex_unlock(&data->status_mutex);
		}
		usleep(500);
	}
	return (NULL);
}
