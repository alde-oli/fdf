/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:25:29 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:28:33 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_u(t_point *point, double angle, char axis)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = point->x;
	tmp_y = point->y;
	tmp_z = point->z;
	if (axis == 'x')
	{
		point->y = tmp_y * cos(angle) - tmp_z * sin(angle);
		point->z = tmp_y * sin(angle) + tmp_z * cos(angle);
	}
	else if (axis == 'y')
	{
		point->x = tmp_x * cos(angle) + tmp_z * sin(angle);
		point->z = -tmp_x * sin(angle) + tmp_z * cos(angle);
	}
	else if (axis == 'z')
	{
		point->x = tmp_x * cos(angle) - tmp_y * sin(angle);
		point->y = tmp_x * sin(angle) + tmp_y * cos(angle);
	}
}

void	ft_translate_u(t_point *point, double mv_x, double mv_y, double mv_z)
{
	if (mv_x)
		point->x += mv_x;
	if (mv_y)
		point->y += mv_y;
	if (mv_z)
		point->z += mv_z;
}

void	ft_scale_u(t_point *point, double factor, char axis)
{
	if (axis == 'x')
		point->x *= factor;
	else if (axis == 'y')
		point->y *= factor;
	else if (axis == 'z')
		point->z *= factor;
}
