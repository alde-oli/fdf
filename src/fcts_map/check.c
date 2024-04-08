/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:16:47 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check_elem_content(char *s)
{
	int	hex_len;

	if (!(*s >= '0' && *s <= '9') && *s != '-')
		return (0);
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == ',' && *(s + 1) == '0' && (*(s + 2) == 'x' || *(s + 2) == 'X')
		&& ((*(s + 3) >= '0' && *(s + 3) <= '9') || (*(s + 3) >= 'A'
				&& *(s + 3) <= 'F') || (*(s + 3) >= 'a' && *(s + 3) <= 'f')))
		s += 3;
	else if (*s == '\0' || *s == '\n')
		return (1);
	else
		return (0);
	hex_len = 10;
	while (hex_len > 0 && ((*s >= '0' && *s <= '9') || (*s >= 'A' && *s <= 'F')
			|| (*s >= 'a' && *s <= 'f')))
	{
		s++;
		hex_len--;
	}
	if (*s == '\0' || *s == '\n')
		return (1);
	else
		return (0);
}

static int	ft_is_content_valid(int fd)
{
	char	*line;
	char	**split;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		i = 0;
		while (split[i])
		{
			if (!ft_check_elem_content(split[i]))
			{
				free(line);
				ft_free_str_tab(split);
				return (1);
			}
			i++;
		}
		ft_free_str_tab(split);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

static int	ft_are_lines_equal(int fd)
{
	char	*line;
	int		elem;
	int		current_elem;

	line = get_next_line(fd);
	elem = 0;
	while (line)
	{
		if (!elem)
			elem = ft_count_words(line, ' ');
		current_elem = ft_count_words(line, ' ');
		if (elem != current_elem)
		{
			free(line);
			close(fd);
			if (elem != current_elem)
				return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

void	ft_check_file(char *file)
{
	char	*extension;
	int		fd;

	extension = ft_strrchr(file, '.');
	if (!extension || ft_strcmp(extension, ".fdf"))
		ft_error(NULL, 'e');
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, 'f');
	if (ft_are_lines_equal(fd))
		ft_error(NULL, 'l');
	close(fd);
	fd = open(file, O_RDONLY);
	if (ft_is_content_valid(fd))
	{
		close(fd);
		ft_error(NULL, 'c');
	}
	else
		close(fd);
}
