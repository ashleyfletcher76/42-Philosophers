/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:50:19 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/10 17:02:05 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	my_sleep(t_philo *philo, u_int64_t time)
{
	useconds_t	time_in_us;

	(void)philo;
	time_in_us = time * 1000;
	usleep(time_in_us);
}

void	status_print(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->general_data->status_mutex);
	printf("%d %d %s\n", get_current_time() - philo->general_data->start_time, philo->id, status);
	pthread_mutex_unlock(&philo->general_data->status_mutex);
}
