/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:02:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/11 13:04:12 by asfletch         ###   ########.fr       */
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
	int				meals_eaten;
	int				last_ate;
	bool			philo_full;
	pthread_t		philo;
	pthread_mutex_t	meal_mutex;
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
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	status_mutex;
	pthread_mutex_t	*num_forks;
}	t_philo_data;

//main
void		start_routine(t_philo_data *data);
void		pick_up_forks(t_philo *philo);
void		eating(t_philo *philo);
void		thinking(t_philo *philo);
void		my_sleep(t_philo *philo, long time);
void		*monitor(void *arg);
void		status_print(t_philo *philo, char *status);
void		start_monitor(t_philo_data *data, pthread_t monitor_thread);

//init
void		init_struct(t_philo_data *data, int argc, char **argv);
void		init_philos(t_philo_data *data);
void		init_mutex_meals(t_philo_data *data);
void		init_forks(t_philo_data *data);

//tools
bool		check_arguments(int	argc, char **argv);
int			current_time(void);

//libft
int			ft_atoi(const char *str);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);

//exit
void		exit_message(char *msg);
void		cleaner(t_philo_data *data);

#endif
