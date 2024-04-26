/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:08:33 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/06 09:49:36 by alde-oli         ###   ########.fr       */
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
