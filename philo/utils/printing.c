/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:30 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/28 09:13:30 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_print(t_arg *arg, int id, char *msg)
{
	long long	now;

	now = get_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(arg->print));
	if (!(arg->is_dead))
		printf("%lld %d %s\n", now - arg->thread_start, id + 1, msg);
	pthread_mutex_unlock(&(arg->print));
	return (0);
}
