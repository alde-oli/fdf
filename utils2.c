/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/29 18:08:54 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}

int	ft_atoi_hexa(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != 'x')
		i++;
	i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 16 + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * 16 + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * 16 + str[i] - 'a' + 10;
		i++;
	}
	return (res);
}
