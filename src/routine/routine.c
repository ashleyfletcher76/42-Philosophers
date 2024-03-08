/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:00:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/08 11:54:13 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine_one(t_philo *philo)
{
	while (1)
	{
		pick_up_forks(philo);
		printf("%llu %d is sleeping\n", get_current_time(), philo->id);
		usleep(philo->general_data->time_to_sleep * 1000);
		printf("%llu %d is thinking\n", get_current_time(), philo->id);
		usleep(1000);
	}
}

// void	routine_one(t_philo *philo)
// {
// 	while (1)
// 	{
// 		if (philo->id % 2 == 1)
// 		{
// 			pthread_mutex_lock(philo->right);
// 			printf("%llu %d has taken a fork\n", get_current_time(), philo->id);
// 			pthread_mutex_lock(philo->left);
// 			printf("%llu %d has taken a fork\n", get_current_time(), philo->id);
// 		}
// 		else
// 		{
// 			pthread_mutex_lock(philo->left);
// 			printf("%llu %d has taken a fork\n", get_current_time(), philo->id);
// 			pthread_mutex_lock(philo->right);
// 			printf("%llu %d has taken a fork\n", get_current_time(), philo->id);
// 		}
// 		printf("%llu %d is eating\n", get_current_time(), philo->id);
// 		usleep(philo->general_data->time_to_eat * 1000);
// 		pthread_mutex_unlock(philo->right);
// 		pthread_mutex_unlock(philo->left);
// 		printf("%llu %d is sleeping\n", get_current_time(), philo->id);
// 		usleep(philo->general_data->time_to_sleep * 1000);
// 		printf("%llu %d is thinking\n", get_current_time(), philo->id);
// 		usleep(1000);
// 	}
// }

void	routine_two(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->general_data->num_meals)
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
		printf("%llu %d is sleeping\n", get_current_time(), philo->id);
		usleep(philo->general_data->time_to_sleep * 1000);
		printf("%llu %d is thinking\n", get_current_time(), philo->id);
		usleep(1000);
		i++;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->general_data->num_meals == -1)
		routine_one(philo);
	else
		routine_two(philo);
	return (NULL);
}

void	start_routine(t_philo_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].philo, NULL,
			 philo_routine, (void *)&data->philos[i]) != 0)
			exit_message("Thread creation failed");
	}
	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_join(data->philos[i].philo, NULL) != 0)
			exit_message("Join failure");
	}
}
