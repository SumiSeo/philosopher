#ifndef PHILO_H
# define PHILO_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "limits.h"
#include <sys/time.h> 


typedef struct s_arg
{
	int num_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_must_eat;
	int is_dead;
	int finished_eat;
	long long thread_start;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
	pthread_mutex_t time;
} t_arg;

typedef struct s_philo
{
	int id;
	int count_eat;
	int left;
	int right;
	long last_eat;
	pthread_t thread;
	struct s_arg *arg;
} t_philo;


//error handler
int print_error(char *msg);


//parsing
int	ft_atoi(const char *nbtr, int *error);
long long	get_time(void);
void print_all_info(t_arg *arg);
void philo_print(t_arg *arg, int i, char *s);



//execution
void    philo_check_finish(t_arg *arg,t_philo *philo);


#endif