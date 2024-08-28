/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:24 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/28 09:18:26 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_act(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	philo_print(arg, philo->id, "has taken a fork");
	if (arg->num_of_philo != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right]));
		philo_print(arg, philo->id, "has taken a fork");
		philo_print(arg, philo->id, "is eating");
		philo->last_eat = get_time();
		// printf("SECOND Check last_eat time: %d:  %ld\n", philo->id,
		// 	philo->last_eat);
		philo->count_eat++;
		pass_time((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->right]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	return (1);
}

void	philo_check_finish(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	now;

	i = 0;
	while (!arg->is_dead)
	{
		if ((arg->num_of_must_eat != 0)
			&& (arg->num_of_philo == arg->finished_eat))
		{
			arg->is_dead = 1;
			break ;
		}
		i = 0;
		while (i < arg->num_of_philo)
		{
			now = get_time();
			if ((now - philo[i].last_eat) >= arg->time_to_die)
			{
				philo_print(arg, i, "died");
				arg->is_dead = 1;
				break ;
			}
			i++;
		}
		usleep(1000);
	}
}
