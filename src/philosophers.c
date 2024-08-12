/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:54:57 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/12 17:06:14 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>

void*	routine(void *arg1)
{
	long sum = *((long *) arg1);
	printf("sum is the number : %ld\n", sum);
	return NULL;
}

int	philosophers(char **argv)
{
	(void) argv;
	printf("Philo all is good !\n");

	return (1);
}

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		handle_invalid_argc();
		printf("\n");
		print_exited_with_code(1);
		return (1);
	}
	if (!check_args(argv))
	{
		handle_invalid_argv();
		printf("\n");
		print_exited_with_code(1);
		return (1);
	}
	if (!philosophers(argv))
	{
		philosopher_failed_msg();
		printf("\n");
		print_exited_with_code(1);
		return (1);	
	}


	ft_debug("this is a error !\n");
	

	printf("\n");
	print_exited_with_code(0);
	return (0);
}

