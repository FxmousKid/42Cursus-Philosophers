/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:06:24 by inazaria          #+#    #+#             */
/*   Updated: 2024/09/20 19:56:14 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	destroy_forks_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philo)
	{
		if (data->forks[i].fork_lock_init_status)
			pthread_mutex_destroy(&data->forks[i].fork_lock);
		i++;
	}
}

static void	destroy_data_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philo)
	{
		if (data->write_lock_init_status)
			pthread_mutex_destroy(&data->write_lock);
		if (data->eat_lock_init_status)
			pthread_mutex_destroy(&data->eat_lock);
		if (data->dead_lock_init_status)
			pthread_mutex_destroy(&data->dead_lock);
		i++;
	}
}

void	destroy_data(t_data *data)
{
	destroy_forks_mutex(data);
	destroy_data_mutex(data);
}
