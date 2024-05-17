/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   study.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/05/17 20:19:10 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int				mails = 0;
pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	(void)arg;
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	// information about thread
	(void)argc;
	(void)argv;
	pthread_t t1;
	pthread_t t2;
	pthread_mutex_init(&mutex, NULL);

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (2);
	// finish thread and then finish process
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	pthread_mutex_destroy(&mutex);
	printf("mails count %d\n", mails);
	return (0);
}