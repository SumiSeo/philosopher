#include "philo.h"


int philo_act(t_arg *arg, t_philo *philo)
{
    pthread_mutex_lock(&(arg->forks[philo->left]));
    philo_print(arg, philo->id, "has taken a fork");
    if(arg->num_of_philo!=1)
    {
        pthread_mutex_lock(&(arg->forks[philo->right]));
        philo_print(arg, philo->id, "has taken a fork");
        philo_print(arg, philo->id, "is eating");
        philo->last_eat = get_time();
        philo->count_eat++;
        pass_time((long long)arg->time_to_eat,arg);
        pthread_mutex_unlock(&(arg->forks[philo->right]));

    }
    pthread_mutex_unlock(&(arg->forks[philo->left]));
    return 1;
}

void *thread_act(void *param)
{
    t_arg *arg;
    t_philo *philo;
    philo = param;
    arg = philo->arg;
    //wait the even numbers
    if (philo->id % 2)
        usleep(1000);

    // I am checking is any of philo is dead ? 
    // if no one is dead
    while (!arg->is_dead)
    {
        philo_act(arg, philo);
        if(arg->num_of_must_eat == philo->count_eat)
        {
            arg->finished_eat++;
            break;
        }
        philo_print(arg,philo->id, "is sleeping");
        pass_time((long long)arg->time_to_sleep, arg);
        philo_print(arg,philo->id, "is thiking");
    }
    return (0);
}

int init_thread(t_arg *arg, t_philo *philo)
{

    int i;
    i = 0;

    while (i < arg->num_of_philo)
    {
        philo->last_eat = get_time();
        if (pthread_create(&(philo[i].thread), NULL, thread_act, (void *)&philo[i]))
            return 1;
        i++;
    }
    philo_check_finish(arg,philo);
    i = 0;
    while (i < arg->num_of_philo)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }

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
        (*philo)[i].last_eat = get_time();
        (*philo)[i].left = (i + arg->num_of_philo - 1) % arg->num_of_philo;
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
    return 0;
}