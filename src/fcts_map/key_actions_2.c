/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:19:56 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:17:27 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_save(t_map *map)
{
	ft_map_copy(map->points, map->copy, map->width, map->height);
	ft_push_map(map);
}

void	ft_key_switch_proj(t_map *map, int keycode)
{
	if (keycode == 49)
		map->proj = 'i';
	if (keycode == 50)
		map->proj = 'o';
	if (keycode == 51)
		map->proj = 't';
	ft_push_map(map);
}

static void	ft_re_map(t_map *map, char *file)
{
	int		width;
	int		height;
	double	scale_f;

	height = 0;
	width = 0;
	if (!ft_get_dimensions(file, &width, &height))
		ft_error(map, 'a');
	map = ft_new_map(map, width, height);
	insert_values(map, file);
	map->proj = 'i';
	scale_f = ft_get_scale_factor(map);
	ft_scale(map, scale_f, scale_f, scale_f * 0.6);
	ft_center(map);
	ft_rotate(map, 180, 'x');
	ft_map_copy(map->points, map->copy, map->width, map->height);
}

static void	ft_free_points(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->points[i]);
		free(map->copy[i]);
		i++;
	}
	free(map->points);
	free(map->copy);
}

int	ft_change_map(t_map *map)
{
	char	*file;
	int		fd;

	file = get_next_line(0);
	file[ft_strchr(file, '\n') - file] = '\0';
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "please write a valid file\n", 27);
		free(file);
		return (ft_change_map(map));
	}
	close(fd);
	ft_free_points(map);
	ft_re_map(map, file);
	free(file);
	return (0);
}
