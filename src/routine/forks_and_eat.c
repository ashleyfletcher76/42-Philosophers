/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_and_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:50:13 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/08 11:53:45 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->right);
		printf("%llu %d has taken a fork\n", get_current_time(), philo->id);
		pthread_mutex_lock(philo->left);
		printf("%llu %d has taken a fork\n", get_current_time(), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		printf("%llu %d has taken a fork\n", get_current_time(), philo->id);
		pthread_mutex_lock(philo->right);
		printf("%llu %d has taken a fork\n", get_current_time(), philo->id);
	}
	printf("%llu %d is eating\n", get_current_time(), philo->id);
	usleep(philo->general_data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}
