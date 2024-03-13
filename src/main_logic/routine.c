/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:00:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/13 16:00:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->general_data->status_mutex);
	philo->general_data->start_time = current_time();
	philo->last_ate = current_time();
	pthread_mutex_unlock(&philo->general_data->status_mutex);
	if (philo->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		pick_up_forks(philo);
		eating(philo);
		pthread_mutex_lock(&philo->general_data->status_mutex);
		if (philo->general_data->philo_dead == true)
		{
			pthread_mutex_unlock(&philo->general_data->status_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->general_data->status_mutex);
		status_print(philo, "is sleeping");
		my_wait(philo, philo->general_data->time_to_sleep);
		status_print(philo, "is thinking");
	}
}

void	routine_two(t_philo *philo)
{
	int	i;

	i = 0;
	philo->general_data->start_time = current_time();
	philo->last_ate = current_time();
	if (philo->id % 2 == 1)
		usleep(1000);
	while (i < philo->general_data->num_meals && philo->general_data->philo_dead == false)
	{
		pick_up_forks(philo);
		eating(philo);
		status_print(philo, "is sleeping");
		my_wait(philo, philo->general_data->time_to_sleep);
		status_print(philo, "is thinking");
		i++;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

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
			{
				i = -1;
				while (++i < data->num_philos)
				{
					pthread_mutex_destroy(&data->num_forks[i]);
					pthread_mutex_destroy(&data->philos[i].protect_last);
				}
				pthread_mutex_destroy(&data->status_mutex);
				free (data->philos);
				free (data->num_forks);
				exit_message("Thread creation failed");
			}
	}
}
