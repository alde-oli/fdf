/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/30 13:29:56 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		x, y;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	map = ft_get_map(argv[1]);
	if (map == NULL)
	{
		printf("Erreur lors de la lecture de la carte.\n");
		return (1);
	}
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			printf("(%3d, %3d, %3d, %6X) ", map->points[y][x].x, map->points[y][x].y,
				map->points[y][x].z, map->points[y][x].col);
			x++;
		}
		printf("\n");
		y++;
	}
	ft_free_map(map);
	return (0);
}