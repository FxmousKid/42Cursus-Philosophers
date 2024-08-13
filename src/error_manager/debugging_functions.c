/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:16:18 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/13 16:04:06 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* Function used to debug errors flow, will only trigger when building 
 * project with 'make debug'*/
#ifdef DEBUG

int	ft_debug(char *str)
{
	printf_clr("red");
	printf("%s", str);
	printf_clr("reset");
	return (0);
}

#else

int	ft_debug(char *str)
{
	(void) str;
	return (0);
}
#endif
