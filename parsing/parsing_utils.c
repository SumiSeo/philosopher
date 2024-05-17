/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:49:04 by sumseo            #+#    #+#             */
/*   Updated: 2024/05/17 19:55:25 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *nbtr, int *error)
{
	int i;
	long nb;
	int sign;

	sign = 1;
	i = 0;
	nb = 0;
	while ((nbtr[i] >= '\t' && nbtr[i] <= '\r') || nbtr[i] == ' ')
		i++;
	if (nbtr[i] == '-' || nbtr[i] == '+')
	{
		if (nbtr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nbtr[i] < '0' || nbtr[i] > '9')
		*error = 2;
	while (nbtr[i] >= '0' && nbtr[i] <= '9')
	{
		nb = (nb * 10) + (nbtr[i] - '0');
		i++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		*error = 2;
	return (sign * nb);
}