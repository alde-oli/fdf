/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:01:42 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/31 16:47:33 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_drawing(t_point *start, t_point *end,
		t_point *delta, t_point *step)
{
	delta->x = abs(end->proj_x - start->proj_x);
	delta->y = abs(end->proj_y - start->proj_y);
	if (start->proj_x < end->proj_x)
		step->x = 1;
	else
		step->x = -1;
	if (start->proj_y < end->proj_y)
		step->y = 1;
	else
		step->y = -1;
}

static void	ft_update_pos(t_point *cur, t_point step, t_point delta, int *err)
{
	int	e2;

	e2 = *err;
	if (e2 > -delta.x)
	{
		*err -= delta.y;
		cur->proj_x += step.x;
	}
	if (e2 < delta.y)
	{
		*err += delta.x;
		cur->proj_y += step.y;
	}
}

static int	ft_get_color(t_point *start, t_point *end,
	t_point current, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	ratio;

	if (delta.x > delta.y)
		ratio = fabs((double)(current.proj_x - start->proj_x) / delta.x);
	else
		ratio = fabs((double)(current.proj_y - start->proj_y) / delta.y);
	red = (int)((1 - ratio) * ((start->col >> 16) & 0xFF)
			+ ratio * ((end->col >> 16) & 0xFF));
	green = (int)((1 - ratio) * ((start->col >> 8) & 0xFF)
			+ ratio * ((end->col >> 8) & 0xFF));
	blue = (int)((1 - ratio) * (start->col & 0xFF) + ratio * (end->col & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

void	ft_draw_line(t_point *start, t_point *end, t_mlx *mlx)
{
	t_point	delta;
	t_point	step;
	t_point	current;
	int		error;

	ft_init_drawing(start, end, &delta, &step);
	current = *start;
	if (delta.x > delta.y)
		error = delta.x / 2;
	else
		error = -delta.y / 2;
	while (1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, current.proj_x,
			current.proj_y, ft_get_color(start, end, current, delta));
		if (current.proj_x == end->proj_x && current.proj_y == end->proj_y)
			break ;
		ft_update_pos(&current, step, delta, &error);
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
				ft_draw_line(&(map->points[i][j]), &(map->points[i][j + 1]), map->mlx);
			if (i < map->height - 1)
				ft_draw_line(&(map->points[i][j]), &(map->points[i + 1][j]), map->mlx);
			j++;
		}
		i++;
	}
}
