/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/31 07:20:51 by alde-oli         ###   ########.fr       */
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
				y++;
			}
			free(map->points);
		}
		free(map);
	}
}

void	ft_center_map(t_map *map)
{
	const int	dx = -(map->width / 2);
	const int	dy = -(map->height / 2);
	int			i;
	int			j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			translate_point(&(map->points[i][j]), dx, dy, 0);
			j++;
		}
		i++;
	}
}
