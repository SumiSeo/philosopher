/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:44 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/28 15:31:43 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_error(char *msg)
{
	printf("%s", msg);
	return (EXIT_FAILURE);
}

void	free_all(t_arg *arg, t_philo *philo)
{
	int i;
	i = 0;
	while (i < arg->num_of_philo)
	{
		free(philo);
		i++;
	}
	free(arg->forks);
}