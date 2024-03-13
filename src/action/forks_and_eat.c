/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_and_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:50:13 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/13 15:46:32 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_forks(t_philo *philo)
{
	if (philo->left > philo->right)
	{
		pthread_mutex_lock(philo->left);
		status_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right);
		status_print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right);
		status_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left);
		status_print(philo, "has taken a fork");
	}
}

void	eating(t_philo *philo)
{
	status_print(philo, "is eating");
	pthread_mutex_lock(&philo->protect_last);
	philo->last_ate = current_time();
	pthread_mutex_unlock(&philo->protect_last);
	my_wait(philo, philo->general_data->time_to_eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}
