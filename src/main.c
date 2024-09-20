/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:54:57 by inazaria          #+#    #+#             */
/*   Updated: 2024/09/20 19:59:06 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdbool.h>



bool	start_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, simulate_philo, 
			&data->philos[i]) != 0)
			return (debug(DBG("Failed to pthread_create()")), false) ;	
		i++;
	}

	return (true);
}

bool	philosophers(char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (!init_philosophers(&data, argv))
	{
		destroy_data(&data);
		debug(DBG("Failed to init_philosophers()"));
		return (false);
	}
	if (!start_philosophers(&data))
	{
		destroy_data(&data);
		debug(DBG("Failed to start_philosophers()"));
		return (false);
	}
	destroy_data(&data);
	return (true);
}

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		handle_invalid_argc();
		return (1);
	}
	if (!check_args(argv))
	{
		handle_invalid_argv();
		return (1);
	}
	if (!philosophers(argv))
	{
		philosopher_failed_msg();
		return (1);	
	}
	return (0);
}

