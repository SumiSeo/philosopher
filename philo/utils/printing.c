#include "../philo.h"

void print_fork(int i)
{
    printf("%d has taken a fork\n", i);
}

void print_eating(int i)
{
    printf("%d is eating\n", i);
}
void print_sleeping(int i)
{
    printf("%d is sleeping\n", i);
}
void print_thinking(int i)
{
    printf("%d is thinking\n", i);
}
void print_died(int i)
{
    printf("%d died", i);
}