/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:00:59 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/07 11:16:22 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_data	data;
	int				i;

	i = -1;
	if (argc < 5 || argc > 6)
		exit_message("Too few or too many args!");
	if (check_arguments(argc, argv))
		exit_message("Not all numeric args loooooool");
	init_struct(&data, argc, argv);
	init_philos(&data);
	start_routine(&data);
	while (++i < data.num_philos)
		pthread_mutex_destroy(&data.num_forks[i]);
	pthread_mutex_destroy(data.num_forks);
	return (0);
}
