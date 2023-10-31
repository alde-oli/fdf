/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:33:51 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/31 16:52:16 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate(t_map *map, double angle, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_rotate_u(&map->points[i][j], angle, axis);
			j++;
		}
		i++;
	}
}

void	ft_translate(t_map *map, double mv_x, double mv_y, double mv_z)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_translate_u(&map->points[i][j], mv_x, mv_y, mv_z);
			j++;
		}
		i++;
	}
}

void	ft_scale(t_map *map, double factor, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_scale_u(&map->points[i][j], factor, axis);
			j++;
		}
		i++;
	}
}
