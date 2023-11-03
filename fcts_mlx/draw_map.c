/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:01:42 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/03 14:58:13 by alde-oli         ###   ########.fr       */
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

void	ft_draw_vertical(t_map *map, t_point p1, t_point p2)
{
	int		y_start;
	int		y_end;
	int		y_step;
	int		color;

	y_start = p1.proj_y;
	y_end = p2.proj_y;
	if (y_start <= y_end)
		y_step = 1;
	else
		y_step = -1;
	color = p1.col;
	while (y_start != y_end)
	{
		if (p1.proj_x >= 0 && p1.proj_x < map->screen_w && y_start
			>= 0 && y_start < map->screen_h)
			my_mlx_pixel_put(&map->img, p1.proj_x, y_start, color);
		y_start += y_step;
	}
}

void	ft_draw_line(t_map *map, t_point p1, t_point p2)
{
	int		steps;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;

	if (p1.proj_x == p2.proj_x)
	{
		ft_draw_vertical(map, p1, p2);
		return ;
	}
	steps = fmax(abs(p2.proj_x - p1.proj_x), abs(p2.proj_y - p1.proj_y));
	x_inc = (double)(p2.proj_x - p1.proj_x) / steps;
	y_inc = (double)(p2.proj_y - p1.proj_y) / steps;
	x = p1.proj_x;
	y = p1.proj_y;
	while (steps-- >= 0)
	{
		if (x >= 0 && x < map->screen_w && y >= 0 && y < map->screen_h)
			my_mlx_pixel_put(&map->img, x, y, p1.col);
		x += x_inc;
		y += y_inc;
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

void	ft_push_map(t_map *map)
{
	mlx_destroy_image(map->mlx.mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx.mlx, map->screen_w, map->screen_h);
	ft_project(map);
	ft_draw_map(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
}
