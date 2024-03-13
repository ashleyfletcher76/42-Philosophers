/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:49:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/13 10:40:19 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_overflow(long int converted_int, int sign)
{
	if (sign == 1 && converted_int > INT_MAX)
		return (1);
	if (sign == -1 && converted_int > INT_MAX)
	{
		if (converted_int > INT_MAX + 1L)
			return (1);
		else if (converted_int == INT_MAX + 1L)
			return (0);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	converted_int;

	i = 0;
	sign = 1;
	converted_int = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		|| (str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		converted_int = converted_int * 10 + (str[i] - '0');
		if (check_overflow(converted_int, sign))
			return (0);
		i++;
	}
	return (sign * converted_int);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
