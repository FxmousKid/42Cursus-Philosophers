/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:32:42 by inazaria          #+#    #+#             */
/*   Updated: 2024/07/27 00:41:07 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int		check_args(char **argv)
{
	if (raw_atoi_long(argv[1]) < 2 || raw_atoi_long(argv[1]) > 200)
		return (0);
	if (raw_atoi_long(argv[2]) < 1 || raw_atoi_long(argv[2]) > 10000)
		return (0);
	if (raw_atoi_long(argv[3]) < 1 || raw_atoi_long(argv[3]) > 10000)
		return (0);
	if (raw_atoi_long(argv[4]) < 1 || raw_atoi_long(argv[4]) > 10000)
		return (0);
	return (1);
}

void	handle_invalid_argc(void)
{
	printf_clr("red");
	printf("Invalid argument count of ./philosophers\n");
	printf_clr("reset");
	printf("Usage : ");
	printf_clr("yellow");
	printf("./philosophers <number_of_philosophers time_to_die time_to_eat \
	time_to_sleep>\n");
	printf_clr("reset");
}

void	handle_invalid_argv(void)
{
	printf_clr("red");
	printf("Invalid argument count of ./philosophers\n");
	printf_clr("reset");
	printf("Usage : ");
	printf_clr("yellow");
	printf("./philosophers <number_of_philosophers time_to_die time_to_eat \
	time_to_sleep>\n\n");
	printf_clr("yellow");
	printf("number_of_philosophers : ");
	printf_clr("reset");
	printf("1 < n < 200\n");
	printf_clr("yellow");
	printf("time_to_die : ");
	printf_clr("reset");
	printf("1 < n < 10000\n");
	printf_clr("yellow");
	printf("time_to_eat : ");
	printf_clr("reset");
	printf("1 < n < 10000\n");
	printf_clr("yellow");
	printf("time_to_sleep : ");
	printf_clr("reset");
	printf("1 < n < 10000\n");
}

void	print_exited_with_code(int code)
{
	printf_clr("bold");
	printf("Exited with code : ");
	printf_clr("red");
	printf("%d\n", code);
	printf_clr("reset");
}
