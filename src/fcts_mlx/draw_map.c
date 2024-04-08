/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:01:42 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:27:48 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_get_percentage(int current, int start, int end, int steps)
{
	double	position;

	position = (double)(current - start) / (end - start);
	if (steps == 0)
		return (1.0);
	else
		return (position);
}

static void	ft_draw_gradient_line(t_map *map, t_point p1, t_point p2, int steps)
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

static void	ft_draw_line(t_map *map, t_point p1, t_point p2)
{
	int	steps;

	if (p1.proj_x == p2.proj_x)
	{
		ft_draw_vertical(map, p1, p2);
		return ;
	}
	steps = ft_get_steps(p1, p2);
	ft_draw_gradient_line(map, p1, p2, steps);
}


static void	ft_draw_map(t_map *map)
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
