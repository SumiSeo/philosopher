/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:13:10 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/31 17:56:56 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pass_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = get_time();
	pthread_mutex_lock(&(arg->dead_mutex));
	while (!arg->is_dead)
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		pthread_mutex_unlock(&(arg->dead_mutex));
		usleep(10);
		pthread_mutex_lock(&(arg->dead_mutex));
	}
	pthread_mutex_unlock(&(arg->dead_mutex));
}

long long	get_time(void)
{
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL) == -1)
		return (-1);
	return ((mytime.tv_sec * 1000) + (mytime.tv_usec / 1000));
}

int	ft_atoi(const char *nbtr, int *error)
{
	int		i;
	long	nb;
	int		sign;

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) == '\0' || *(unsigned char *)(s1
				+ i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
