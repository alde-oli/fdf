/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbooooows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:35:56 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/03 14:23:50 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_shift_color(int current_color)
{
	int	red;
	int	green;
	int	blue;

	red = (current_color >> 16) & 0xFF;
	green = (current_color >> 8) & 0xFF;
	blue = current_color & 0xFF;
	if (red == 0xFF && green < 0xFF && blue == 0)
		green += 0x11;
	else if (red > 0 && green == 0xFF && blue == 0)
		red -= 0x11;
	else if (red == 0 && green == 0xFF && blue < 0xFF)
		blue += 0x11;
	else if (red == 0 && green > 0 && blue == 0xFF)
		green -= 0x11;
	else if (red < 0xFF && green == 0 && blue == 0xFF)
		red += 0x11;
	else if (red == 0xFF && green == 0 && blue > 0)
		blue -= 0x11;
	else
		return (0xFFFFFF);
	return (((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF));
}

void	ft_my_little_poney(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->points[i][j].col == 0XFFFFFF)
				map->points[i][j].col = 0XFF0000;
			else
				map->points[i][j].col = ft_shift_color(map->points[i][j].col);
			j++;
		}
		i++;
	}
	ft_rotate(map, 10, 'x');
	ft_rotate(map, -8, 'y');
	ft_rotate(map, 5, 'z');
}
