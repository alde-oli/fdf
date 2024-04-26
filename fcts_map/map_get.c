/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/06 09:45:48 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_get_dimensions(char *file, int *width, int *height)
{
	int		fd;
	char	*line;
	char	**split_line;

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
	if (fd > -1)
		close(fd);
	return (1);
}

t_map	*ft_new_map(t_map *new_map, int width, int height)
{
	int		i;

	new_map->width = width;
	new_map->height = height;
	new_map->points = ft_calloc(height * sizeof(t_point *));
	new_map->copy = ft_calloc(height * sizeof(t_point *));
	if (!new_map->points || !new_map->copy)
		ft_error(new_map, 'a');
	i = 0;
	while (i < height)
	{
		new_map->points[i] = ft_calloc(width * sizeof(t_point));
		new_map->copy[i] = ft_calloc(width * sizeof(t_point));
		if (!new_map->points[i] || !new_map->copy[i])
		{
			ft_free_map(new_map);
			ft_error(new_map, 'a');
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

void	insert_values(t_map *map, char *file)
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
	if (fd > -1)
		close(fd);
}

t_map	*ft_get_map(char *file, int s_w, int s_h)
{
	t_map	*map;
	int		width;
	int		height;
	double	scale_f;

	height = 0;
	width = 0;
	if (!ft_get_dimensions(file, &width, &height))
		return (NULL);
	map = ft_calloc(sizeof(t_map));
	if (!map)
		ft_error(NULL, 'a');
	map = ft_new_map(map, width, height);
	map->screen_w = s_w;
	map->screen_h = s_h;
	insert_values(map, file);
	map->proj = 'i';
	scale_f = ft_get_scale_factor(map);
	ft_start(map);
	ft_scale(map, scale_f, scale_f, scale_f * 0.6);
	ft_center(map);
	ft_rotate(map, 180, 'x');
	ft_map_copy(map->points, map->copy, map->width, map->height);
	return (map);
}
