/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:57:21 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/10 16:46:11 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	start_monitor(t_philo_data *data, pthread_t monitor_thread)
// {
// 	int			i;

// 	i = -1;
// 	printf("inside\n");
// 	while(++i < data->num_philos)
// 	{
// 		if(pthread_join(data->philos[i].philo, NULL) != 0)
// 			exit_message("Thread join failure");
// 	}
// 	if (pthread_join(monitor_thread, NULL) != 0)
// 		exit_message("Monitor thread join failure");
// }

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
			pthread_mutex_lock(&data->philos[i].meal_mutex);
			if (get_current_time() - data->philos[i].last_ate > data->time_to_die)
			{
				printf("%d %d has died\n", get_current_time() - data->philos[i].start_time, data->philos[i].id);
				exit(0);
			}
			pthread_mutex_unlock(&data->philos[i].meal_mutex);
		}
		usleep(1000);
	}
	return (NULL);
}
