/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:36 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/31 18:24:19 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_act(void *param)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = (t_philo *)param;
	arg = philo->arg;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&(arg->dead_mutex));
		if (arg->is_dead)
		{
			pthread_mutex_unlock(&(arg->dead_mutex));
			break ;
		}
		pthread_mutex_unlock(&(arg->dead_mutex));
		philo_act(arg, philo);
		if (arg->num_of_must_eat == philo->count_eat)
		{
			add_finished_eat(arg);
			break ;
		}
		print_status(arg, philo);
	}
	return (NULL);
}

void	add_finished_eat(t_arg *arg)
{
	pthread_mutex_lock(&(arg->dead_mutex));
	arg->finished_eat++;
	pthread_mutex_unlock(&(arg->dead_mutex));
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
	t_arg	arg;
	t_philo	*philo;

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
		free_all(&arg, philo);
	}
	return (0);
}
