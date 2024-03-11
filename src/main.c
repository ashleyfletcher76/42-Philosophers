/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:00:59 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/11 16:36:37 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_data	data;
	pthread_t		monitor_thread;

	if (argc < 5 || argc > 6)
		exit_message("Too few or too many args!");
	if (check_arguments(argc, argv))
		exit_message("Not all numeric args loooooool");
	init_struct(&data, argc, argv);
	init_philos(&data);
	start_routine(&data);
	if (pthread_create(&monitor_thread, NULL, &monitor, (void *)&data) != 0)
		exit_message("Failed to create the monitor");
	start_monitor(&data, monitor_thread);
	cleaner(&data);
	return (0);
}
