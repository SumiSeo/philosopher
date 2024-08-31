/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:18 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/31 17:24:19 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	arg_init_mutex(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&(arg->print), NULL))
		return (1);
	if (pthread_mutex_init(&(arg->dead_mutex), NULL))
		return (1);
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->num_of_philo);
	if (!(arg->forks))
		return (1);
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_mutex_init(&(arg->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_info(t_arg *arg, char **argv)
{
	int	error;

	error = 0;
	arg->num_of_philo = ft_atoi(argv[1], &error);
	arg->time_to_die = ft_atoi(argv[2], &error);
	arg->time_to_eat = ft_atoi(argv[3], &error);
	arg->time_to_sleep = ft_atoi(argv[4], &error);
	arg->thread_start = get_time();
	if (arg->num_of_philo <= 0 || arg->time_to_eat <= 0 || arg->time_to_die <= 0
		|| arg->time_to_sleep <= 0)
		return (1);
	if (argv[5] != NULL)
	{
		arg->num_of_must_eat = ft_atoi(argv[5], &error);
		if (arg->num_of_must_eat <= 0)
			return (1);
	}
	if (arg_init_mutex(arg))
		return (1);
	return (0);
}
