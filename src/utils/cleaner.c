/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:57:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/12 12:00:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cleaner(t_philo_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		pthread_mutex_destroy(&data->num_forks[i]);
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
	}
	pthread_mutex_destroy(&data->status_mutex);
	free(data->num_forks);
	free(data->philos);
}
