#include "../philo.h"

long long	get_time(void)
{
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL) == -1)
		return (-1);
	return ((mytime.tv_sec * 1000) + (mytime.tv_usec / 1000));
}

int	ft_atoi(const char *nbtr, int *error)
{
	int		i;
	long	nb;
	int		sign;

	sign = 1;
	i = 0;
	nb = 0;
	while ((nbtr[i] >= '\t' && nbtr[i] <= '\r') || nbtr[i] == ' ')
		i++;
	if (nbtr[i] == '-' || nbtr[i] == '+')
	{
		if (nbtr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nbtr[i] < '0' || nbtr[i] > '9')
		*error = 2;
	while (nbtr[i] >= '0' && nbtr[i] <= '9')
	{
		nb = (nb * 10) + (nbtr[i] - '0');
		i++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		*error = 2;
	return (sign * nb);
}