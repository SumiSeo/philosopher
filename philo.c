/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:09 by sumseo            #+#    #+#             */
/*   Updated: 2024/05/17 21:26:02 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_argv(char **argv)
{
	int	i;
	int	converted_argv;
	int	limit_flag;

	limit_flag = 1;
	i = 1;
	while (argv[i])
	{
		if (argv[i][0] >= 'a' && argv[i][0] <= 'z')
			exit_program("There is CHAR type in arguments", 4);
		converted_argv = ft_atoi(argv[i], &limit_flag);
		if (limit_flag == 2)
			exit_program("Argument is out of range", 2);
		if (i == 1 && converted_argv > 200)
			exit_program("Maximum number of philosophers are 200", 3);
		printf("each argument %d : %s\n", i, argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc >= 7)
		exit_program("Wrong argument number", 1);
	else
		parsing_argv(argv);
}