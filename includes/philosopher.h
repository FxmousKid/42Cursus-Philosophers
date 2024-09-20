/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:06:01 by inazaria          #+#    #+#             */
/*   Updated: 2024/09/20 19:50:19 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define RED_TXT		"\e[0;31m"
# define GREEN_TXT		"\e[0;32m"
# define YELLOW_TXT		"\e[0;33m"
# define BLUE_TXT		"\e[0;34m"
# define PURPLE_TXT		"\e[0;35m"
# define CYAN_TXT		"\e[0;36m"
# define GREY_TXT		"\e[0;37m"
# define WHITE_TXT		"\e[0;39m"
# define BOLD_TXT		"\e[1m"
# define UNDERLINE_TXT	"\e[4m"
# define REVERSE_TXT	"\e[7m"
# define HIDDEN_TXT		"\e[8m"
# define END_TXT		"\e[0m"


# define STRINGIFY(x) #x
# define TOSTRING(x) STRINGIFY(x)


// Debug Helping
# define DBG(reason)  reason " at line " \
TOSTRING(__LINE__) " in file " __FILE__ "\n"

typedef struct data t_data;
typedef pthread_mutex_t t_mutex;

typedef struct s_fork
{
	bool	fork_lock_init_status;	
	t_mutex	fork_lock;
}			t_fork;

typedef struct philo
{
	pthread_t	thread;
	int			id;
	int			meals_eaten;
	bool		eating;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		meals_to_eat;
	long		start_time;
	long		last_meal_time;
	bool		dead;
	t_data		*data;
}				t_philo;

typedef struct data
{
	pthread_t	monitor_thread;
	t_philo		philos[250];
	t_fork		forks[250];
	t_mutex		write_lock;
	bool		write_lock_init_status;
	t_mutex		dead_lock;
	bool		dead_lock_init_status;
	t_mutex		eat_lock;
	bool		eat_lock_init_status;
	int			dead_flag;
	int			total_philo;
}				t_data;

// Error Handling 
void	debug(char *str);
int		check_args(char **argv);
void	handle_invalid_argc(void);
void	handle_invalid_argv(void);
void	philosopher_failed_msg(void);


// Philosopher
bool	init_philosophers(t_data *data, char **argv);
void	destroy_data(t_data *data);
void	*simulate_philo(void *arg);


// Utils
void	printf_clr(char *clr, char *str);
long	ft_strlen(char *str);
long	raw_atoi_long(char *str);
void	ft_bzero(void *s, size_t n);

#endif
