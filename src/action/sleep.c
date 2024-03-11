/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:50:19 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/11 12:49:43 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	my_sleep(t_philo *philo, long time)
{
	long	start;

	(void)philo;
	start = current_time();
	while ((current_time() - start) < time)
		usleep(500);
}

void	status_print(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->general_data->status_mutex);
	printf("%ld %d %s\n", current_time() - philo->general_data->start_time,
			philo->id, status);
	pthread_mutex_unlock(&philo->general_data->status_mutex);
}
