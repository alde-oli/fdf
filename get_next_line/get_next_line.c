/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:55:49 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/02 11:13:45 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*get_next_line(int fd)
{
	static t_file	f;
	char			*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (fd != f.fd)
	{
		if (f.buf)
			free(f.buf);
		f.fd = fd;
	}
	f.buf = ft_read_line(f.buf, fd);
	if (!f.buf)
		return (NULL);
	line = ft_crop_buf(f.buf);
	f.buf = ft_get_cropped(f.buf);
	return (line);
}

char	*ft_read_line(char *buf, int fd)
{
	char	*to_add;
	int		nb_read;

	nb_read = 1;
	if (!buf)
		buf = ft_calloc(1);
	to_add = ft_calloc(BUFFER_SIZE + 1);
	if (!buf || !to_add)
		return (NULL);
	while (nb_read > 0)
	{
		nb_read = read(fd, to_add, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buf);
			free(to_add);
			return (NULL);
		}
		to_add[nb_read] = '\0';
		buf = ft_strjoin(buf, to_add);
		if (ft_find(buf, 0) > -1)
			break ;
	}
	free(to_add);
	return (buf);
}

char	*ft_crop_buf(char *buf)
{
	int		nl;

	nl = ft_find(buf, 0);
	if (nl == -1)
		return (ft_strndup(buf, ft_find(buf, 1)));
	return (ft_strndup(buf, ft_find(buf, 0)));
}

char	*ft_get_cropped(char *buf)
{
	char	*new_buf;
	int		nl;

	nl = ft_find(buf, 0);
	if (nl == -1)
	{
		free(buf);
		return (NULL);
	}
	new_buf = ft_strndup(buf + nl, ft_find(buf, 1) - ft_find(buf, 0));
	free(buf);
	return (new_buf);
}
