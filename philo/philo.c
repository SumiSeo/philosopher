#include "philo.h"

void init_philos_info(t_philos *philos, char **argv)
{
    (void)philos;
    (void)argv;
}

int main(int argc, char **argv)
{

    t_philos *philos;
    int errno;
    philos = malloc(sizeof(t_philos));
    if (!philos) {
        print_error("Memory allocation for philo-argv failed");
        return 1; 
    }

    if (argc != 5 && argc != 6)
        print_error("error argc");
    else
    {
        printf("fiine for now");
        init_philos_info(philos, argv);
         
    }
   

    free(philos);
    return 0;
}