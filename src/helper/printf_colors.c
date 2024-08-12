/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:39:09 by inazaria          #+#    #+#             */
/*   Updated: 2024/07/27 00:37:48 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	printf_clr(char *str)
{
	if (ft_strcmp(str, "red") == 0)
		printf("\033[0;31m");
	else if (ft_strcmp(str, "green") == 0)
		printf("\033[0;32m");
	else if (ft_strcmp(str, "yellow") == 0)
		printf("\033[0;33m");
	else if (ft_strcmp(str, "blue") == 0)
		printf("\033[0;34m");
	else if (ft_strcmp(str, "magenta") == 0)
		printf("\033[0;35m");
	else if (ft_strcmp(str, "cyan") == 0)
		printf("\033[0;36m");
	else if (ft_strcmp(str, "white") == 0)
		printf("\033[0;37m");
	else if (ft_strcmp(str, "bold") == 0)
		printf("\033[1m");
	else if (ft_strcmp(str, "underline") == 0)
		printf("\033[4m");
	else if (ft_strcmp(str, "reverse") == 0)
		printf("\033[7m");
	else if (ft_strcmp(str, "hidden") == 0)
		printf("\033[8m");
	else if (ft_strcmp(str, "reset") == 0)
		printf("\033[0m");
}
