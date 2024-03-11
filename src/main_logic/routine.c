/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:00:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/11 11:46:45 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine_one(t_philo *philo)
{
	philo->general_data->start_time = current_time();
	philo->last_ate = current_time();
	while (1)
	{
		pick_up_forks(philo);
		eating(philo);
		status_print(philo, "is sleeping");
		my_sleep(philo, philo->general_data->time_to_sleep);
		//thinking(philo);
		status_print(philo, "is thinking");
	}
}

void	routine_two(t_philo *philo)
{
	int	i;

	i = 0;
	philo->general_data->start_time = current_time();
	philo->last_ate = current_time();
	while (i < philo->general_data->num_meals)
	{
		pick_up_forks(philo);
		eating(philo);
		status_print(philo, "is sleeping");
		my_sleep(philo, philo->general_data->time_to_sleep);
		status_print(philo, "is thinking");
		usleep(1000);
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
			exit_message("Thread creation failed");
	}
}
