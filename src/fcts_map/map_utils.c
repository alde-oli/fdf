/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:17:40 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_map *map)
{
	int	y;

	if (map)
	{
		if (map->points)
		{
			y = 0;
			while (y < map->height)
			{
				free(map->points[y]);
				free(map->copy[y]);
				y++;
			}
			free(map->points);
			free(map->copy);
		}
		free(map);
	}
}

void	ft_minmax(t_point *min, t_point *max, t_point *current)
{
	if (current->x < min->x)
		min->x = current->x;
	if (current->y < min->y)
		min->y = current->y;
	if (current->z < min->z)
		min->z = current->z;
	if (current->x > max->x)
		max->x = current->x;
	if (current->y > max->y)
		max->y = current->y;
	if (current->z > max->z)
		max->z = current->z;
}

double	ft_get_scale_factor(t_map *map)
{
	double	scale_x;
	double	scale_y;

	if (map->screen_w > map->screen_h)
	{
		scale_x = (map->screen_h) / (map->width);
		scale_y = (map->screen_h) / (map->height);
	}
	else
	{
		scale_x = (map->screen_w) / (map->width);
		scale_y = (map->screen_w) / (map->height);
	}
	if (scale_y < scale_x)
		return (scale_y * 0.5);
	return (scale_x * 0.5);
}

void	ft_map_copy(t_point **tab_from, t_point **tab_to, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			tab_to[i][j] = tab_from[i][j];
			j++;
		}
		i++;
	}
}
