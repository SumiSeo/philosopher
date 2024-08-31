/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:18:03 by sumseo            #+#    #+#             */
/*   Updated: 2024/08/31 18:12:53 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "limits.h"
# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_arg
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				finished_eat;
	long long		thread_start;
	int				is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
}					t_arg;

typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				left;
	int				right;
	long			last_eat_time;
	pthread_t		thread;
	struct s_arg	*arg;
}					t_philo;

int					print_error(char *msg);
int					ft_atoi(const char *nbtr, int *error);
long long			get_time(void);
void				pass_time(long long wait_time, t_arg *arg);
void				print_all_info(t_arg *arg);
int					philo_print(t_arg *arg, int id, char *msg);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					arg_init_mutex(t_arg *arg);
int					init_info(t_arg *arg, char **argv);
void				free_all(t_arg *arg, t_philo *philo);
void				philo_check_finish(t_arg *arg, t_philo *philo);
int					philo_act(t_arg *arg, t_philo *philo);
void				print_status(t_arg *arg, t_philo *philo);
void				add_finished_eat(t_arg *arg);
void				is_really_dead(int i, t_arg *arg, t_philo *philo);
#endif