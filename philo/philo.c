/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:36 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/28 14:27:24 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_act(void *param)
{
	t_arg	*arg;
	t_philo	*philo;
	int		i;

	philo = param;
	arg = philo->arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	i = 0;
	while (!arg->is_dead)
	{
		philo_act(arg, philo);
		if (arg->num_of_must_eat == philo->count_eat)
		{
			arg->finished_eat++;
			break ;
		}
		philo_print(arg, i, "is sleeping");
		pass_time((long long)arg->time_to_sleep, arg);
		philo_print(arg, philo->id, "is thinking");
	}
	return (0);
}

int	init_thread(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		philo[i].last_eat_time = get_time();
		if (pthread_create(&philo[i].thread, NULL, thread_act,
				(void *)&philo[i]))
			return (1);
		i++;
	}
	i = 0;
	philo_check_finish(arg, philo);
	while (i < arg->num_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (0);
}

int	init_philo(t_arg *arg, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * arg->num_of_philo);
	if (!(*philo))
		return (1);
	while (i < arg->num_of_philo)
	{
		(*philo)[i].arg = arg;
		(*philo)[i].id = i;
		(*philo)[i].count_eat = 0;
		(*philo)[i].last_eat_time = get_time();
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % arg->num_of_philo;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg arg;
	t_philo *philo;
	memset(&arg, 0, sizeof(t_arg));
	if (argc != 5 && argc != 6)
		print_error("Please check argument number\n");
	else
	{
		if (init_info(&arg, argv))
			return (print_error("args init fail\n"));
		if (init_philo(&arg, &philo))
			return (print_error("philo init fail\n"));
		if (init_thread(&arg, philo))
			return (print_error("thread start fail"));
	}
	printf("Everyone is full");
	return (0);
}