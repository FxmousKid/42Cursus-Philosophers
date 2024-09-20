/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:06:53 by inazaria          #+#    #+#             */
/*   Updated: 2024/09/20 19:57:53 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdbool.h>

static bool init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philo)
	{
		if (pthread_mutex_init(&data->forks[i].fork_lock, NULL) != 0)
		{
			debug(DBG("Failed to init forks"));
			return (false);
		}
		data->forks[i].fork_lock_init_status = true;
		i++;
	}
	return (true);
}

static bool	init_single_philo(t_philo *p, t_data *data, char **argv, int i)
{
	p->id = i + 1;
	p->time_to_die = raw_atoi_long(argv[2]);
	p->time_to_eat = raw_atoi_long(argv[3]);
	p->time_to_sleep = raw_atoi_long(argv[4]);
	if (argv[5])
		p->meals_to_eat = raw_atoi_long(argv[5]);
	else
		p->meals_to_eat = -1;
	p->dead = false;
	p->eating = false;	
	p->data = data;
	return (true);
}

bool	init_philosophers(t_data *data, char **argv)
{
	int	i;
	
	i = 0;
	data->total_philo = raw_atoi_long(argv[1]);
	while (i < data->total_philo)
	{
		if (!init_single_philo(&data->philos[i], data, argv, i))
			return (debug(DBG("Failed to init_single_philo()")), false);
		i++;
	}
	return (true);	
}

static bool	init_and_check_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
	{
		data->write_lock_init_status = false;
		debug(DBG("Failed to init write_lock"));
		return (false);
	}
	data->write_lock_init_status = true;
	if (pthread_mutex_init(&data->eat_lock, NULL) != 0)
	{
		data->write_lock_init_status = false;
		debug(DBG("Failed to init eat_lock"));
		return (false);
	}
	data->eat_lock_init_status = true;
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
	{
		data->write_lock_init_status = false;
		debug(DBG("Failed to init dead_lock"));
		return (false);
	}
	data->dead_lock_init_status = true;
	return (true);
}

bool	init_data(t_data *data, char *argv[])
{
	if (!init_philosophers(data, argv))
		return (debug(DBG("Failed to init_philosophers()")), false);
	if (!init_and_check_mutexes(data))
		return (debug(DBG("Failed to init_and_check_mutexes")), false);	
	if (!init_forks(data))
		return (debug(DBG("Failed to init_forks()")), false);
	return (true);
}
