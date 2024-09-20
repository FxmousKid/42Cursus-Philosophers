/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:24:52 by inazaria          #+#    #+#             */
/*   Updated: 2024/09/20 14:36:44 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <bits/getopt_core.h>

long	ft_strlen(char *str)
{
	long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}


long	raw_atoi_long(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (str && *str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (str && *str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	if (ft_strlen(s1) > ft_strlen(s2))
		return (1);
	if (ft_strlen(s1) == ft_strlen(s2))
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	printf_clr(char *clr, char *str)
{
	printf("%s%s%s", clr, str, END_TXT);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}
