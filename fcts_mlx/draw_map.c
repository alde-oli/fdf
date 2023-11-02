/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:01:42 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/02 12:04:18 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_gradient(int start, int end, double percentage)
{
	int		red;
	int		green;
	int		blue;

	red = (1 - percentage) * (start >> 16 & 0xFF)
		+ percentage * (end >> 16 & 0xFF);
	green = (1 - percentage) * (start >> 8 & 0xFF)
		+ percentage * (end >> 8 & 0xFF);
	blue = (1 - percentage) * (start & 0xFF) + percentage * (end & 0xFF);
	return (red << 16 | green << 8 | blue);
}

void	ft_draw_line(t_map *map, t_point p1, t_point p2)
{
	int		steps;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;

	if (abs(p2.proj_x - p1.proj_x) > abs(p2.proj_y - p1.proj_y))
		steps = abs(p2.proj_x - p1.proj_x);
	else
		steps = abs(p2.proj_y - p1.proj_y);
	x_inc = (p2.proj_x - p1.proj_x) / (double)steps;
	y_inc = (p2.proj_y - p1.proj_y) / (double)steps;
	x = p1.proj_x;
	y = p1.proj_y;
	while (steps >= 0)
	{
		if (x >= 0 && x < map->screen_w && y >= 0 && y < map->screen_h)
			my_mlx_pixel_put(&map->img, x, y, ft_gradient(p1.col, p2.col,
					(x - p1.proj_x) / (p2.proj_x - p1.proj_x)));
		x += x_inc;
		y += y_inc;
		steps--;
	}
}

void	ft_draw_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (j < map->width - 1)
				ft_draw_line(map, map->points[i][j], map->points[i][j + 1]);
			if (i < map->height - 1)
				ft_draw_line(map, map->points[i][j], map->points[i + 1][j]);
			j++;
		}
		i++;
	}
}
