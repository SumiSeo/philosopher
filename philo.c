/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/05/17 22:35:37 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_argv(char **argv, t_philo *philo)
{
	int	i;
	int	converted_argv;
	int	limit_flag;

	limit_flag = 1;
	i = 1;
	if (argv == NULL)
		exit_program("Invalid arguments", 1);
	while (argv[i])
	{
		if (argv[i][0] >= 'a' && argv[i][0] <= 'z')
			exit_program("There is CHAR type in arguments", 4);
		converted_argv = ft_atoi(argv[i], &limit_flag);
		if (limit_flag == 2)
			exit_program("Argument is out of range", 2);
		if (i == 1 && converted_argv > 200)
			exit_program("Maximum number of philosophers are 200", 3);
		else if (i == 1 && converted_argv <= 200)
			philo->num_of_philos = converted_argv;
		else if (i == 2)
			philo->time_to_die = converted_argv;
		else if (i == 3)
			philo->time_to_eat = converted_argv;
		else if (i == 4)
			philo->time_to_sleep = converted_argv;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo *philo;

	if (argc < 5 || argc >= 7)
		exit_program("Wrong argument number", 1);

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		exit_program("Memory allocation failed", 5);

	parsing_argv(argv, philo);
	printf("philo check %d\n", philo->num_of_philos);
}