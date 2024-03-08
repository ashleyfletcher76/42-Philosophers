/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:02:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/08 11:52:54 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <stdint.h>

typedef struct	s_philo_data t_philo_data;

typedef struct	s_philo
{
	int				id;
	pthread_t		philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_philo_data	*general_data;
}	t_philo;

typedef struct s_philo_data
{
	long			num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_meals;
	t_philo			*philos;
	pthread_mutex_t	*num_forks;
}	t_philo_data;

//main
void		start_routine(t_philo_data *data);
void		pick_up_forks(t_philo *philo);

//init
void		init_struct(t_philo_data *data, int argc, char **argv);
void		init_philos(t_philo_data *data);

//tools
bool		check_arguments(int	argc, char **argv);
u_int64_t	get_current_time(void);

//libft
int			ft_atoi(const char *str);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);

//exit
void		exit_message(char *msg);

#endif
