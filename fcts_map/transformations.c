/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:33:51 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/03 09:56:22 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_rotate(t_map *map, double angle, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_rotate_u(&map->points[i][j], angle * (PI / 180), axis);
			j++;
		}
		i++;
	}
	ft_push_map(map);
}

void	ft_translate(t_map *map, double mv_x, double mv_y, double mv_z)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_translate_u(&map->points[i][j], mv_x, mv_y, mv_z);
			j++;
		}
		i++;
	}
	ft_push_map(map);
}

static void	ft_scale_axis(t_map *map, double factor, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_scale_u(&map->points[i][j], factor, axis);
			j++;
		}
		i++;
	}
}

void	ft_scale(t_map *map, double x, double y, double z)
{
	if (x == 0)
		x = 1;
	if (y == 0)
		y = 1;
	if (z == 0)
		z = 1;
	ft_scale_axis(map, x, 'x');
	ft_scale_axis(map, y, 'y');
	ft_scale_axis(map, z, 'z');
	ft_push_map(map);
}

void	ft_center(t_map *map)
{
	int		i;
	int		j;
	t_point	min;
	t_point	max;

	min = map->points[0][0];
	max = map->points[0][0];
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_minmax(&min, &max, &(map->points[i][j]));
			j++;
		}
		i++;
	}
	ft_translate(map, -(min.x + max.x) / 2, -(min.y + max.y) / 2, 0);
	ft_push_map(map);
}
