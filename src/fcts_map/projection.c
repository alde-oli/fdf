/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:54 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:18:58 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_project_iso(t_point *pt, int screen_w, int screen_h)
{
	int	iso_x;
	int	iso_y;

	iso_x = (pt->x - pt->y) * cos(PI / 6);
	iso_y = (pt->x + pt->y) * sin(PI / 6) - pt->z;
	pt->proj_x = iso_x + screen_w / 2;
	pt->proj_y = screen_h / 2 - iso_y;
}

void	ft_project_ortho(t_point *pt, int screen_w, int screen_h)
{
	pt->proj_x = pt->x + screen_w / 2;
	pt->proj_y = screen_h / 2 - pt->y;
}

static void	ft_projection_type(t_point *pt, t_map *map, char proj)
{
	if (proj == 'i')
		ft_project_iso(pt, map->screen_h, map->screen_w);
	if (proj == 'o')
		ft_project_ortho(pt, map->screen_h, map->screen_w);
	if (proj == 't')
		ft_project_tri(pt, map->screen_h, map->screen_w);
}

void	ft_project(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_projection_type(&(map->points[i][j]), map, map->proj);
			j++;
		}
		i++;
	}
}

void	ft_project_tri(t_point *pt, int screen_w, int screen_h)
{
	double	alpha;
	double	beta;
	double	gamma;
	int		trimetric_x;
	int		trimetric_y;

	alpha = PI / 7;
	beta = PI / 6;
	gamma = PI / 12;
	trimetric_x = pt->x * cos(alpha) - pt->y * sin(beta);
	trimetric_y = pt->x * sin(alpha) + pt->y * cos(beta) - pt->z * sin(gamma);
	pt->proj_x = trimetric_x + screen_w / 2;
	pt->proj_y = screen_h / 2 - trimetric_y;
}
