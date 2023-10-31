/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/31 17:39:54 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_dimensions(char *file, int *width, int *height)
{
	int		fd;
	char	*line;
	char	**split_line;

	*height = 0;
	*width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && *line != '\0')
	{
		if (*height == 0)
		{
			split_line = ft_split(line, ' ');
			while (split_line[*width])
				(*width)++;
			ft_free_str_tab(split_line);
		}
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static t_map	*ft_new_map(int width, int height)
{
	t_map	*new_map;
	int		i;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->width = width;
	new_map->height = height;
	new_map->points = malloc(height * sizeof(t_point *));
	if (!new_map->points)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map->points[i] = malloc(width * sizeof(t_point));
		if (!new_map->points[i])
		{
			ft_free_map(new_map);
			return (NULL);
		}
		i++;
	}
	return (new_map);
}

static void	ft_set_point(t_point *point, char *value, int x, int y)
{
	char	*comma_pos;

	comma_pos = ft_strchr(value, ',');
	if (comma_pos != NULL)
	{
		*comma_pos = '\0';
		point->col = ft_atoi_hexa(comma_pos + 1);
	}
	else
		point->col = 0xFFFFFF;
	point->z = (double)ft_atoi(value);
	point->x = (double)x;
	point->y = (double)y;
}

static void	insert_values(t_map *map, char *file)
{
	int		x;
	int		y;
	char	*line;
	char	**values;
	int		fd;

	y = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line && y < map->height)
	{
		x = 0;
		values = ft_split(line, ' ');
		while (x < map->width)
		{
			ft_set_point(&map->points[y][x], values[x], x, y);
			x++;
		}
		ft_free_str_tab(values);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
}

t_map	*ft_get_map(char *file, int screen_w, int screen_h)
{
	t_map	*map;
	int		width;
	int		height;

	if (!ft_get_dimensions(file, &width, &height))
		return (NULL);
	map = ft_new_map(width, height);
	if (!map)
		return (NULL);
	map->screen_w = screen_w;
	map->screen_h = screen_h;
	insert_values(map, file);
	//ft_center_map(map);
	return (map);
}
