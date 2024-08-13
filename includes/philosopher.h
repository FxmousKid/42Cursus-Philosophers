/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:06:01 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/13 15:59:53 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

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
# define DEBUG_LINE_FILE(reason) "Failed " reason " at line " \
TOSTRING(__LINE__) " in file " __FILE__ "\n"


// Error Handling 
int		ft_debug(char *str);
void	printf_clr(char *str);
int		check_args(char **argv);
void	handle_invalid_argc(void);
void	handle_invalid_argv(void);
void	philosopher_failed_msg(void);
void	print_exited_with_code(int code);

// Utils
long	raw_atoi_long(char *str);

#endif
