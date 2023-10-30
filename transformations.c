/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:25:29 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/30 17:56:11 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate(t_point *point, double angle, char axis)
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

void	ft_translate(t_point *point, double distance, char axis)
{
	if (axis == 'x')
		point->x += distance;
	else if (axis == 'y')
		point->y += distance;
	else if (axis == 'z')
		point->z += distance;
}

void	ft_scale(t_point *point, double factor, char axis)
{
	if (axis == 'x')
		point->x *= factor;
	else if (axis == 'y')
		point->y *= factor;
	else if (axis == 'z')
		point->z *= factor;
}
