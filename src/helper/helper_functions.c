/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:24:52 by inazaria          #+#    #+#             */
/*   Updated: 2024/08/13 00:49:21 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
