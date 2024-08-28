/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:44 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/28 15:47:30 by sumseo           ###   ########.fr       */
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
	int		i;

	if (philo != NULL)
	{
		if (arg->forks != NULL)
		{
			i = 0;
			while (i < arg->num_of_philo)
			{
				pthread_mutex_destroy(&(arg->forks[i]));
				i++;
			}
			free(arg->forks);
		}
		free(philo);
	}
	pthread_mutex_destroy(&(arg->print));
}
