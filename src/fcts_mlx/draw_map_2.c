/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:22:48 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:27:34 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
