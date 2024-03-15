/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:57:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/15 09:46:14 by asfletch         ###   ########.fr       */
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
			exit_message("Join failure");
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		exit_message("Monitor thread join failure");
}

void	*monitor(void *arg)
{
	t_philo_data	*data;
	int				i;

	data = (t_philo_data *)arg;
	i = -1;
	while (!all_philos_full(data))
	{
		i = -1;
		while (++i < data->num_philos)
		{
			pthread_mutex_lock(&data->status_mutex);
			pthread_mutex_lock(&data->philos[i].protect_last);
			if (current_time() - data->philos[i].last_ate > data->time_to_die
				&& !data->philos[i].philo_full)
			{
				philo_died(data, i);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philos[i].protect_last);
			pthread_mutex_unlock(&data->status_mutex);
		}
		usleep(200);
	}
	return (NULL);
}

bool	all_philos_full(t_philo_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (!data->philos[i].philo_full)
			return (false);
	}
	return (true);
}

void	philo_died(t_philo_data *data, int i)
{
	pthread_mutex_unlock(&data->philos[i].protect_last);
	printf("%ld %d died\n", current_time() - data->start_time,
		data->philos[i].id);
	data->philo_dead = true;
	pthread_mutex_unlock(&data->status_mutex);
}
