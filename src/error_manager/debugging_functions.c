/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:16:18 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/12 17:06:16 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* Function used to debug errors flow, will only trigger when building 
 * project with 'make debug'*/
#ifdef DEBUG

void	ft_debug(char *str)
{
	printf_clr("red");
	printf("%s", str);
	printf_clr("reset");
}

#else

void	ft_debug(char *str)
{
	(void) str;
}
#endif
