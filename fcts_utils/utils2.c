/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/05 16:02:03 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_atoi(char *str)
{
	double	n;
	int		sign;

	n = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
		n = n * 10 + (*str++ - '0');
	return (n * sign);
}

int	ft_atoi_hexa(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != 'x')
		i++;
	i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 16 + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = n * 16 + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			n = n * 16 + str[i] - 'a' + 10;
		i++;
	}
	return (n);
}

void	*ft_calloc(int size)
{
	void	*ptr;
	int		i;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strrchr(char *s, char c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0 && s[i] != c)
	{
		i--;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	else
		return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1 && s2)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (1);
}
