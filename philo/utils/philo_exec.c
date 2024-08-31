/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:24 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/31 18:37:09 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_one_fork_act(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	philo_print(arg, philo->id, "has taken a fork");
	pthread_mutex_unlock(&(arg->forks[philo->left]));
}

int	philo_act(t_arg *arg, t_philo *philo)
{
	if (arg->num_of_philo == 1)
		philo_one_fork_act(arg, philo);
	else
	{
		if (philo->id % 2)
		{
			pthread_mutex_lock(&(arg->forks[philo->left]));
			philo_print(arg, philo->id, "has taken a fork");
			pthread_mutex_lock(&(arg->forks[philo->right]));
			philo_print(arg, philo->id, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(&(arg->forks[philo->right]));
			philo_print(arg, philo->id, "has taken a fork");
			pthread_mutex_lock(&(arg->forks[philo->left]));
			philo_print(arg, philo->id, "has taken a fork");
		}
		philo_print(arg, philo->id, "is eating");
		pthread_mutex_lock(&(arg->dead_mutex));
		philo->last_eat_time = get_time();
		pthread_mutex_unlock(&(arg->dead_mutex));
		unlock_mutex_fork(arg, philo);
	}
	return (1);
}

void	unlock_mutex_fork(t_arg *arg, t_philo *philo)
{
	philo->count_eat++;
	pass_time((long long)arg->time_to_eat, arg);
	pthread_mutex_unlock(&(arg->forks[philo->right]));
	pthread_mutex_unlock(&(arg->forks[philo->left]));
}

void	philo_check_finish(t_arg *arg, t_philo *philo)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(&(arg->dead_mutex));
		if (arg->is_dead)
		{
			pthread_mutex_unlock(&(arg->dead_mutex));
			break ;
		}
		if (arg->num_of_must_eat != 0 && arg->finished_eat >= arg->num_of_philo)
		{
			printf("Everyone is full\n");
			arg->is_dead = 1;
			pthread_mutex_unlock(&(arg->dead_mutex));
			break ;
		}
		pthread_mutex_unlock(&(arg->dead_mutex));
		i = 0;
		is_really_dead(i, arg, philo);
		usleep(100);
	}
}

void	is_really_dead(int i, t_arg *arg, t_philo *philo)
{
	long long	now;

	while (i < arg->num_of_philo)
	{
		now = get_time();
		pthread_mutex_lock(&(arg->dead_mutex));
		if (now - philo[i].last_eat_time >= arg->time_to_die)
		{
			philo_print(arg, i, "is dead");
			arg->is_dead = 1;
			pthread_mutex_unlock(&(arg->dead_mutex));
			break ;
		}
		pthread_mutex_unlock(&(arg->dead_mutex));
		i++;
	}
}
