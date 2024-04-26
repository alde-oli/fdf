/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:51:16 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/06 09:56:35 by alde-oli         ###   ########.fr       */
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

int	ft_get_steps(t_point p1, t_point p2)
{
	return (fmax(abs(p2.proj_x - p1.proj_x), abs(p2.proj_y - p1.proj_y)));
}

double	ft_get_percentage(int current, int start, int end, int steps)
{
	double	position;

	position = (double)(current - start) / (end - start);
	if (steps == 0)
		return (1.0);
	else
		return (position);
}

void	ft_draw_gradient_line(t_map *map, t_point p1, t_point p2, int steps)
{
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;
	int		current_color;

	x_inc = (double)(p2.proj_x - p1.proj_x) / steps;
	y_inc = (double)(p2.proj_y - p1.proj_y) / steps;
	x = p1.proj_x;
	y = p1.proj_y;
	while (steps-- > 0)
	{
		current_color = ft_gradient(p1.col, p2.col,
				ft_get_percentage((int)x, p1.proj_x, p2.proj_x, steps));
		if ((int)x >= 0 && (int)x < map->screen_w
			&& (int)y >= 0 && (int)y < map->screen_h)
			my_mlx_pixel_put(&map->img, (int)x, (int)y, current_color);
		x += x_inc;
		y += y_inc;
	}
}
