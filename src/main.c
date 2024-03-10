/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:00:59 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/10 15:30:33 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_data	data;
	pthread_t		monitor_thread;
	int				i;

	i = -1;
	if (argc < 5 || argc > 6)
		exit_message("Too few or too many args!");
	if (check_arguments(argc, argv))
		exit_message("Not all numeric args loooooool");
	init_struct(&data, argc, argv);
	init_philos(&data);
	start_routine(&data);
	if (pthread_create(&monitor_thread, NULL, &monitor, (void *)&data) != 0)
		exit_message("Failed to create the monitor");
	while (++i < data.num_philos)
	{
		if (pthread_join(data.philos[i].philo, NULL) != 0)
			exit_message("Join failure");
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		exit_message("Monitor thread join failure");
	i = -1;
	while (++i < data.num_philos)
	{
		pthread_mutex_destroy(&data.num_forks[i]);
		pthread_mutex_destroy(&data.philos[i].meal_mutex);
	}
	free(data.num_forks);
	free(data.philos);
	return (0);
}
