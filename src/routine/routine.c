/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:00:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/09 13:17:33 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine_one(t_philo *philo)
{
	philo->start_time = get_current_time();
	while (1)
	{
		pick_up_forks(philo);
		eating(philo);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		// if (get_current_time() - philo->meals_eaten > (u_int64_t)philo->general_data->time_to_die)
		// {
		// 	printf("Philo %d has died\n", philo->id);
		// 	break ;
		// }
		printf("%llu %d is sleeping\n", get_current_time(), philo->id);
		my_sleep(philo, philo->general_data->time_to_sleep);
		printf("%llu %d is thinking\n", get_current_time(), philo->id);
		usleep(100);
	}
}

void	routine_two(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->general_data->num_meals)
	{
		pick_up_forks(philo);
		eating(philo);
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

// void	routine_one(t_philo *philo)
// {
// 	u_int64_t	last_ate;

// 	last_ate = get_current_time();
// 	while (1)
// 	{
// 		pick_up_forks(philo);
// 		eating(philo);
// 		printf("%llu %d is eating\n", get_current_time(), philo->id);
// 		last_ate = get_current_time();
// 		usleep(philo->general_data->time_to_eat * 1000);
// 		pthread_mutex_unlock(philo->right);
// 		pthread_mutex_unlock(philo->left);
// 		if (get_current_time() - last_ate > (u_int64_t)philo->general_data->time_to_die)
// 		{
// 			printf("Philo %d has died\n", philo->id);
// 			break ;
// 		}
// 		printf("%llu %d is sleeping\n", get_current_time(), philo->id);
// 		usleep(philo->general_data->time_to_sleep * 1000);
// 		printf("%llu %d is thinking\n", get_current_time(), philo->id);
// 		usleep(100);
// 	}
// }

// void	routine_one(t_philo *philo)
// {
// 	u_int64_t	last_ate;

// 	last_ate = get_current_time();
// 	while (1)
// 	{
// 		pick_up_forks_and_eat(philo);
// 		printf("%llu %d is sleeping\n", get_current_time(), philo->id);
// 		usleep(philo->general_data->time_to_sleep * 1000);
// 		printf("%llu %d is thinking\n", get_current_time(), philo->id);
// 		usleep(1000);
// 	}
// }
