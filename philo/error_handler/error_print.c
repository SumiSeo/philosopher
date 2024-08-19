#include "../philo.h"

void print_error(char *msg)
{
    printf("%s", msg);
}

void print_all_info(t_philos *philos)
{
      printf("philos check %d\n",philos->num_of_philo);
        printf("philos check %d\n",philos->time_to_die);
        printf("philos check %d\n",philos->time_to_eat);
        printf("philos check %d\n",philos->time_to_sleep);
        printf("philos check %d\n",philos->num_of_must_eat);
}