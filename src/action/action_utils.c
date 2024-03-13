/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:50:19 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/13 10:35:34 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_wait(t_philo *philo, long time)
{
	long	start;

	(void)philo;
	start = current_time();
	while ((current_time() - start) < time)
		usleep(200);
}

void	status_print(t_philo *philo, char *status)
{
	if (!philo->general_data->philo_dead)
	{
		pthread_mutex_lock(&philo->general_data->status_mutex);
		printf("%ld %d %s\n", current_time() - philo->general_data->start_time,
			philo->id, status);
		pthread_mutex_unlock(&philo->general_data->status_mutex);
	}
}

int	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}
