/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:08:33 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/03 14:58:38 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

double	ft_calculate_focal_length(t_map *map)
{
	double	max_distance;
	int		i;
	int		j;
	double	distance;

	max_distance = 0.0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			distance = fabs(map->points[i][j].z);
			if (distance > max_distance)
			{
				max_distance = distance;
			}
			j++;
		}
		i++;
	}
	return (max_distance / 2.0);
}

void	ft_project_persp(t_point *pt, int screen_w,
	int screen_h, double focal_length)
{
	double	ratio;
	double	persp_x;
	double	persp_y;

	ratio = focal_length / (focal_length + pt->z);
	persp_x = pt->x * ratio;
	persp_y = pt->y * ratio;
	pt->proj_x = (int)(persp_x + (screen_w / 2));
	pt->proj_y = (int)((screen_h / 2) - persp_y);
}
