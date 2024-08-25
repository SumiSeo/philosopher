#include "../philo.h"


void    philo_check_finish(t_arg *arg,t_philo *philo)
{
    int i;
    long long now;

i = 0;
    //check if philo has eaten "must_eat" times or one of philo is dead
    while(!arg->is_dead)
    {   
        if((arg->num_of_must_eat !=0) && (arg->num_of_philo == arg->finished_eat))
        {
            arg->is_dead =1;
            break;
        }
        while(i< arg->num_of_philo)
        {
            now = get_time();
            if((now-philo[i].last_eat) >= arg->time_to_die)
            {
                philo_print(arg,i,"died");
                arg->is_dead = 1;
                break;
            }
            i++;
        }
    }
}
