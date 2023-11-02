/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:32:52 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/02 11:13:42 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_find(char *s, int mod)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!mod && s[i] == '\n')
			return (i + 1);
		i++;
	}
	if (mod)
		return (i);
	return (-1);
}

char	*ft_calloc(int size)
{
	char	*str;
	int		i;

	str = (char *) malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strndup(char *src, int max)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_find(src, 1);
	if (len > max)
		len = max;
	dest = ft_calloc(len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *buf, char *to_add)
{
	char	*dest;
	int		i;
	int		j;

	if (!buf || !to_add)
		return (NULL);
	i = 0;
	j = ft_find(buf, 1) + ft_find(to_add, 1);
	dest = ft_calloc(j + 1);
	j = 0;
	if (!dest)
		return (NULL);
	while (buf[i])
	{
		dest[i] = buf[i];
		i++;
	}
	while (to_add[j])
	{
		dest[i + j] = to_add[j];
		j++;
	}
	free(buf);
	return (dest);
}
