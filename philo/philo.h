#ifndef PHILO_H
# define PHILO_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
typedef struct s_philos
{
	int num_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_must_eat;
	int is_alive;
} t_philos;

typedef struct s_philo
{

	int id;
	int count_eat;
	int left;
	int right;
	long last_eat;
	long thread_start;
	pthread_t t_thread;
} t_philo;


//error handler
void print_error(char *msg);


//parsing

#endif