/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_and_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:50:13 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/10 17:05:11 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	pick_up_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->right);
		status_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left);
		status_print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left);
		status_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right);
		status_print(philo, "has taken a fork");
	}
}

void	eating(t_philo *philo)
{
	status_print(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals_eaten++;
	philo->last_ate = get_current_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	my_sleep(philo, philo->general_data->time_to_eat);
}
