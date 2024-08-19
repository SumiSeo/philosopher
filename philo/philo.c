#include "philo.h"

int init_philos_info(t_philos *philos, char **argv)
{
    int error;

    error = 0;
    philos->is_alive = 1;
    philos->num_of_philo = ft_atoi(argv[1], &error);
    philos->time_to_die = ft_atoi(argv[2], &error);
    philos->time_to_eat = ft_atoi(argv[3], &error);
    philos->time_to_sleep = ft_atoi(argv[4], &error);
   
    if (argv[5] != NULL)
    {
        philos->num_of_must_eat = ft_atoi(argv[5], &error);
        if (error)
            philos->num_of_must_eat = -1;
    }
    else
        philos->num_of_must_eat = -1;
  if (error)
    {
        printf("Error in argument conversion\n");
        return 0;
    }
    return 1;
}

void *routine()
{
    printf("TEST for threa\n");
    return NULL;
}
void init_threads(t_philos *philos)
{
    pthread_t t1[philos->num_of_philo];
    int i;
    i = 0;
    if (pthread_create(&t1, NULL, &routine, NULL))
    {
        // if pthread create is 0 , there is an error //should error handler
        // return 1;
    }
    // the name is join but actually it waits until the thread execution ends
}

void destroy_threads(pthread_t t1)
{
    pthread_join(t1, NULL);
}

int main(int argc, char **argv)
{

    t_philos *philos;
    // pthread_mutex_t mutex;

    int errno;
    philos = malloc(sizeof(t_philos));
    if (!philos)
    {
        print_error("Memory allocation for philo-argv failed");
        return 1;
    }

    if (argc != 5 && argc != 6)
        print_error("Please check argument number\n");
    else
    {
        //check arguments
        if(!init_philos_info(philos, argv))
            return 1;
        //create thread
        init_threads(philos);
        
       
    }
//  print_all_info(philos);
    free(philos);
    return 0;
}