#include "philo.h"
int init_mutex(t_arg *arg)
{
    int i;
    if (pthread_mutex_init(&(arg->print), NULL))
        return 1;
    if (pthread_mutex_init(&(arg->time), NULL))
        return 1;
    arg->forks = malloc(sizeof(pthread_mutex_t) * arg->num_of_philo);
    if (!(arg->forks))
        return 1;
    i = 0;
    while (i < arg->num_of_philo)
    {
        if (pthread_mutex_init(&(arg->forks[i]), NULL))
            return 1;
        i++;
    }
    return 0;
}

int init_info(t_arg *arg, char **argv)
{
    int error;

    error = 0;
    arg->num_of_philo = ft_atoi(argv[1], &error);
    arg->time_to_die = ft_atoi(argv[2], &error);
    arg->time_to_eat = ft_atoi(argv[3], &error);
    arg->time_to_sleep = ft_atoi(argv[4], &error);
    arg->thread_start = get_time();

    if (arg->num_of_philo <= 0 || arg->time_to_eat <= 0 || arg->time_to_die <= 0 || arg->time_to_sleep <= 0)
        return 1;
    if (argv[5] != NULL)
        arg->num_of_must_eat = ft_atoi(argv[5], &error);
    if (init_mutex(arg))
        return 1;
    return 0;
}

void *philo_act(void *argv)
{
    printf("HEllo I am thinkning\n");
    // (void)philo;
    (void)argv;
    return NULL;
}

int init_thread(t_arg *arg, t_philo *philo)
{
   
    int i;
    i = 0;
    while (i < arg->num_of_philo)
    { 
        philo->last_eat = get_time();
        if (pthread_create(&(philo[i].thread), NULL, philo_act, &(philo[i])))
            return 1;
        i++;
    }
    i = 0;
    while (i < arg->num_of_philo)
        pthread_join(philo[i++].thread, NULL);
    return 0;
}

int init_philo(t_arg *arg, t_philo **philo)
{
    int i;
    i = 0;
    *philo = malloc(sizeof(t_philo) * arg->num_of_philo);
    if (!(*philo))
        return 1;
    while (i < arg->num_of_philo)
    {
        (*philo)[i].arg = arg;
        (*philo)[i].id = i;
        (*philo)[i].count_eat = 0;
        (*philo)[i].left = i;
        (*philo)[i].right = (i + 1) % arg->num_of_philo;
        i++;
    }
    return 0;
}

int main(int argc, char **argv)
{

    t_arg arg;
    t_philo *philo;
    int errno;
    memset(&arg, 0, sizeof(t_arg));
    if (argc != 5 && argc != 6)
        print_error("Please check argument number\n");
    else
    {
        if (init_info(&arg, argv))
            return print_error("args init fail\n");
        if (init_philo(&arg, &philo))
            return print_error("philo init fail\n");
        if (init_thread(&arg, philo))
            return (print_error("thread start fail"));
    }
    print_all_info(&arg);
    return 0;
}