#include "../philo.h"

int print_error(char *msg)
{
  printf("%s", msg);
  return EXIT_FAILURE;
}

void print_all_info(t_arg *arg)
{
  printf("arg check num of philo: %d\n", arg->num_of_philo);
  printf("arg check time to die : %d\n", arg->time_to_die);
  printf("arg check time to eat : %d\n", arg->time_to_eat);
  printf("arg check timem to sleep : %d\n", arg->time_to_sleep);
  printf("arg check must eat : %d\n", arg->num_of_must_eat);
}