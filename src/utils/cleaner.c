/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:57:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/14 17:13:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleaner(t_philo_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (&data->num_forks[i])
			pthread_mutex_destroy(&data->num_forks[i]);
		pthread_mutex_destroy(&data->philos[i].protect_last);
	}
	pthread_mutex_destroy(&data->status_mutex);
	if (data->num_forks)
		free(data->num_forks);
	if (data->philos)
		free(data->philos);
}

void	free_some(t_philo_data *data)
{
	if (data->num_forks)
		free (data->num_forks);
	if (data->philos)
		free (data->philos);
	pthread_mutex_destroy(&data->status_mutex);
	exit_message("Mutex init failure");
}
