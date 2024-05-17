/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:35:44 by sumseo            #+#    #+#             */
/*   Updated: 2024/05/17 20:09:41 by sumseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	exit_program(char *s, int error)
{
	if (error == 1)
		printf("%s\n", s);
	else if (error == 2)
		printf("%s\n", s);
	else if (error == 3)
		printf("%s\n", s);
	else if (error == 4)
		printf("%s\n", s);
	exit(EXIT_FAILURE);
}