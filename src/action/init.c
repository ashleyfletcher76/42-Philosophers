/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/13 14:32:26 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo_data *data, int argc, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = (u_int32_t) ft_atoi(argv[2]);
	data->time_to_eat = (u_int32_t) ft_atoi(argv[3]);
	data->time_to_sleep = (u_int32_t) ft_atoi(argv[4]);
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = -1;
	data->philo_dead = false;
	data->start_time = 0;
	data->philos = 0;
	if (pthread_mutex_init(&data->status_mutex, NULL) != 0)
		exit_message("Failed log mutex");
}

void	init_forks(t_philo_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	data->num_forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->num_forks)
	{
		free (data->philos);
		pthread_mutex_destroy(&data->status_mutex);
		exit_message("Failed forks looool\n");
	}
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&data->num_forks[i], NULL) != 0)
		{
			j = -1;
			while (++j < i)
				pthread_mutex_destroy(&data->num_forks[j]);
			free_some(data);
		}
	}
}

void	init_protect_last(t_philo_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&data->philos[i].protect_last, NULL) != 0)
		{
			j = -1;
			while (++j < i)
				pthread_mutex_destroy(&data->philos[j].protect_last);
			free_some(data);
		}
	}
}

void	init_philos(t_philo_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
	{
		pthread_mutex_destroy(&data->status_mutex);
		exit_message("Malloc for philo peeps failed");
	}
	init_forks(data);
	while (++i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].general_data = data;
		data->philos[i].left = &data->num_forks[i];
		data->philos[i].right = &data->num_forks[(i + 1) % data->num_philos];
		data->philos[i].philo_full = false;
		data->philos[i].last_ate = 0;
	}
	init_protect_last(data);
	if (!data->philos->general_data)
		exit_message("no good\n");
}
