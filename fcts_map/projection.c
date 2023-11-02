/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:54 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/02 16:23:50 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_project_point(t_point *pt, int screen_w, int screen_h)
{
	int	iso_x;
	int	iso_y;

	iso_x = (pt->x - pt->y) * cos(PI / 6);
	iso_y = (pt->x + pt->y) * sin(PI / 6) - pt->z;
	pt->proj_x = iso_x + screen_w / 2;
	pt->proj_y = screen_h / 2 - iso_y;
}

void	ft_project_point_ortho(t_point *pt, int screen_w, int screen_h)
{
	pt->proj_x = pt->x + screen_w / 2;
	pt->proj_y = screen_h / 2 - pt->y;
}

void	ft_proj_perspective(t_point *pt, int screen_w, int screen_h, double fov)
{
	double	scale;

	scale = fov / (100 + pt->z);
	pt->proj_x = pt->x * scale + screen_w / 2;
	pt->proj_y = screen_h / 2 - (pt->y * scale);
}

void	ft_proj_stereo(t_point *pt, int screen_w, int screen_h, double radius)
{
	double	denom;

	denom = radius - pt->z;
	if (denom == 0)
		denom = 0.0001;
	pt->proj_x = (radius * pt->x / denom) + screen_w / 2;
	pt->proj_y = screen_h / 2 - (radius * pt->y / denom);
}


void	ft_project(t_map *map, char proj)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (proj == 'i')
				ft_project_point(&(map->points[i][j]),
					map->screen_w, map->screen_h);
			if (proj == 'o')
				ft_project_point_ortho(&(map->points[i][j]),
					map->screen_w, map->screen_h);
			if (proj == 'p')
				ft_proj_perspective(&(map->points[i][j]),
					map->screen_w, map->screen_h, 90);
			if (proj == 's')
				ft_proj_stereo(&(map->points[i][j]),
					map->screen_w, map->screen_h, 50);
			j++;
		}
		i++;
	}
}
