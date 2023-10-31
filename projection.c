/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:54 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/31 16:54:06 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_project_unit(t_point *point, int width, int height, double angle)
{
	const double	offset_x = width / 2.0;
	const double	offset_y = height / 2.0;

	point->proj_x = (int)(offset_x + (point->x - point->y) * cos(angle));
	point->proj_y = (int)(offset_y
			+ (point->x + point->y) * sin(angle) - point->z);
}

void	ft_project(t_map *map, double angle)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_project_unit(&map->points[i][j], map->screen_w, map->screen_h, angle);
			j++;
		}
		i++;
	}
}
