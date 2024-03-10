/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_and_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:50:13 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/10 16:41:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->right);
		printf("%d %d has taken a fork\n", get_current_time() - philo->start_time, philo->id);
		pthread_mutex_lock(philo->left);
		printf("%d %d has taken a fork\n", get_current_time() - philo->start_time, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		printf("%d %d has taken a fork\n", get_current_time() - philo->start_time, philo->id);
		pthread_mutex_lock(philo->right);
		printf("%d %d has taken a fork\n", get_current_time() - philo->start_time, philo->id);
	}
}

void	eating(t_philo *philo)
{
	printf("%d %d is eating\n", get_current_time() - philo->start_time, philo->id);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals_eaten++;
	philo->last_ate = get_current_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	my_sleep(philo, philo->general_data->time_to_eat);
}
