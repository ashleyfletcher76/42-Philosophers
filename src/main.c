/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:00:59 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/06 13:05:26 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_message(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	init_struct(char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ;
	philo->num_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	printf("num_philos = %ld\n", philo->num_philos);
	printf("time_to_die = %ld\n", philo->time_to_die);
	printf("time_to_eat = %ld\n", philo->time_to_eat);
	printf("time_to_sleep = %ld\n", philo->time_to_sleep);
}

bool	check_arguments(int	argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		exit_message("Too few or too many args!");
	if (check_arguments(argc, argv))
		exit_message("Not all numeric args loooooool");
	init_struct(argv);
	return (0);
}
