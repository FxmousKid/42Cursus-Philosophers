/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:32:42 by inazaria          #+#    #+#             */
/*   Updated: 2024/09/20 11:55:21 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int		check_args(char **argv)
{
	if (raw_atoi_long(argv[1]) < 2 || raw_atoi_long(argv[1]) > 250)
		return (0);
	if (raw_atoi_long(argv[2]) < 1 || raw_atoi_long(argv[2]) > INT_MAX)
		return (0);
	if (raw_atoi_long(argv[3]) < 1 || raw_atoi_long(argv[3]) > INT_MAX)
		return (0);
	if (raw_atoi_long(argv[4]) < 1 || raw_atoi_long(argv[4]) > INT_MAX)
		return (0);
	return (1);
}

void	handle_invalid_argc(void)
{
	printf_clr(RED_TXT, "Invalid number of arguments\n");
	printf_clr(YELLOW_TXT, "Usage : ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

void	handle_invalid_argv(void)
{
	printf_clr(RED_TXT, "Invalid arguments\n");
	printf_clr(YELLOW_TXT, "Usage : ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

void	philosopher_failed_msg(void)
{
	printf_clr(RED_TXT, "Philosopher failed to create\n");
}
