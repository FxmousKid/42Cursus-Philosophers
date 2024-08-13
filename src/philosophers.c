/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:54:57 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/13 16:03:53 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;


void*	routine()
{
	for (int i = 0; i < 10000; i++)
	{
		
		mails++;
	}

	return NULL;
}

int	philosophers(char **argv)
{
	(void) argv;

	pthread_t t1;
	pthread_t t2;

	if (!pthread_mutex_init(&mutex, NULL))
		return (ft_debug(DEBUG_LINE_FILE("to create mutex")));	


	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);


	printf("total mails: %d\n", mails);

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

	printf("\n");
	print_exited_with_code(0);
	return (0);
}

