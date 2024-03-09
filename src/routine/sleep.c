/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:50:19 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/09 13:15:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	my_sleep(t_philo *philo, u_int64_t time)
{
	int	current;

	(void)philo;
	current = get_current_time();
	while ((get_current_time() - current) < time)
		usleep(500);
}
