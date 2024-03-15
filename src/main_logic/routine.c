/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:00:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/15 11:44:52 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_one(t_philo *philo)
{
	while (1)
	{
		pick_up_forks(philo);
		eating(philo);
		pthread_mutex_lock(&philo->gen_data->status_mutex);
		if (philo->gen_data->philo_dead == true)
		{
			pthread_mutex_unlock(&philo->gen_data->status_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->gen_data->status_mutex);
		if (!philo->philo_full)
			routine_helper(philo);
	}
}

void	routine_two(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->gen_data->num_meals)
	{
		pick_up_forks(philo);
		eating(philo);
		pthread_mutex_lock(&philo->gen_data->status_mutex);
		if (philo->gen_data->philo_dead == true)
		{
			pthread_mutex_unlock(&philo->gen_data->status_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->gen_data->status_mutex);
		if (!philo->philo_full)
			routine_helper(philo);
		i++;
	}
	pthread_mutex_lock(&philo->gen_data->status_mutex);
	philo->philo_full = true;
	pthread_mutex_unlock(&philo->gen_data->status_mutex);
}

void	routine_helper(t_philo *philo)
{
	status_print(philo, "is sleeping");
	my_wait(philo, philo->gen_data->time_to_sleep);
	status_print(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->protect_last);
	philo->last_ate = current_time();
	pthread_mutex_unlock(&philo->protect_last);
	if (philo->gen_data->num_philos == 1)
		return (one_philosopher(philo), NULL);
	if (philo->id % 2 == 1)
		usleep(500);
	if (philo->gen_data->num_meals == -1)
		routine_one(philo);
	else
		routine_two(philo);
	return (NULL);
}

void	start_routine(t_philo_data *data)
{
	int	i;

	i = -1;
	data->start_time = current_time();
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
			free_some(data);
			return ;
		}
	}
}
