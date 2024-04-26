/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:01:42 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/06 09:57:10 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
