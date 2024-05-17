/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:12 by sumseo            #+#    #+#             */
/*   Updated: 2024/05/17 21:56:13 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// struct
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	bool			is_dead;
	bool			is_eating;
	bool			is_sleeping;
	bool			is_thinking;
}					t_philo;

// error handler
void				exit_program(char *s, int error);

// parsing arguments
void				parsing_argv(char **argv, t_philo *philo);
int					ft_atoi(const char *nbtr, int *error);

// init thread