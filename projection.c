/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:54 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/01 15:26:37 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_project_point(t_point *pt, int screen_w, int screen_h, double angle)
{
	int		iso_x;
	int		iso_y;

	iso_x = (pt->x - pt->y) * cos(angle);
	iso_y = -pt->z + (pt->x + pt->y) * sin(angle);

	pt->proj_x = iso_x + screen_w / 2;
	pt->proj_y = iso_y + screen_h / 2;
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
			ft_project_point(&(map->points[i][j]),
				map->screen_w, map->screen_h, angle);
			j++;
		}
		i++;
	}
}
