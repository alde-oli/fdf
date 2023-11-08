/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbooooows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:35:56 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:28:26 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void	ft_color_fade(t_map *map)
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
				map->points[i][j].col = 0X88FF00;
			else
				map->points[i][j].col = ft_shift_color(map->points[i][j].col);
			j++;
		}
		i++;
	}
}

static int	ft_rand_sign(void)
{
	if (rand() % 2 == 0)
		return (1);
	else
		return (-1);
}

double	ft_rand_scale(void)
{
	double	scale;

	scale = rand() % 104 * ft_rand_sign();
	if ((scale > -97 && scale < 97))
		return (ft_rand_scale());
	return (scale / 100);
}

//rand is illegal in 42, but this is github and tho power of my little poney is too strong to be contained by the norminette
void	ft_my_little_poney(t_map *map)
{
	ft_color_fade(map);

	ft_rotate(map, rand() % 15 * ft_rand_sign(), 'x');
	ft_rotate(map, rand() % 15 * ft_rand_sign(), 'y');
	ft_rotate(map, rand() % 15 * ft_rand_sign(), 'z');
	ft_translate(map, rand() % 15 * ft_rand_sign(),
		rand() % 15 * ft_rand_sign(), rand() % 15 * ft_rand_sign());
	ft_scale(map, ft_rand_scale(), ft_rand_scale(), ft_rand_scale());
}
