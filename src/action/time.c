/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:25:11 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/11 11:12:10 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}

// void	thinking(t_philo *philo)
// {
// 	int	think_time;

// 	think_time = rand() % 10;
// 	status_print(philo, "is thinking");
// 	my_sleep(philo, think_time);
// }
