/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:00:59 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/15 11:14:37 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_data	data;
	pthread_t		monitor_thread;

	monitor_thread = 0;
	if (argc < 5 || argc > 6)
		exit_message("Too few or too many args!");
	if (check_arguments(argc, argv))
		exit_message("Not all numeric args loooooool");
	init_struct(&data, argc, argv);
	if (data.num_philos == 0 || data.num_meals == 0)
	{
		pthread_mutex_destroy(&data.status_mutex);
		return (exit_message("Incorrect number"), 2);
	}
	init_philos(&data);
	start_routine(&data);
	if (pthread_create(&monitor_thread, NULL, &monitor, (void *)&data) != 0)
	{
		cleaner(&data);
		exit_message("Failed to create the monitor");
	}
	start_monitor(&data, monitor_thread);
	cleaner(&data);
	return (0);
}
