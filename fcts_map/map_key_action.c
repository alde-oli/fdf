/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_key_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:09:31 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/03 10:35:50 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_key_rotate(int keycode, t_map *map)
{
	if (keycode == 12)
		ft_rotate(map, 5, 'x');
	if (keycode == 0)
		ft_rotate(map, -5, 'x');
	if (keycode == 13)
		ft_rotate(map, 5, 'y');
	if (keycode == 1)
		ft_rotate(map, -5, 'y');
	if (keycode == 14)
		ft_rotate(map, 5, 'z');
	if (keycode == 2)
		ft_rotate(map, -5, 'z');
}

void	ft_key_translate(int keycode, t_map *map)
{
	if (keycode == 86)
		ft_translate(map, 5, 0, 0);
	if (keycode == 83)
		ft_translate(map, -5, 0, 0);
	if (keycode == 87)
		ft_translate(map, 0, 5, 0);
	if (keycode == 84)
		ft_translate(map, 0, -5, 0);
	if (keycode == 88)
		ft_translate(map, 0, 0, 5);
	if (keycode == 85)
		ft_translate(map, 0, 0, -5);
}

void	ft_key_scale(int keycode, t_map *map)
{
	if (keycode == 15)
		ft_scale(map, 1.1, 0, 0);
	if (keycode == 3)
		ft_scale(map, 0.9, 0, 0);
	if (keycode == 17)
		ft_scale(map, 0, 1.1, 0);
	if (keycode == 5)
		ft_scale(map, 0, 0.9, 0);
	if (keycode == 16)
		ft_scale(map, 0, 0, 1.1);
	if (keycode == 4)
		ft_scale(map, 0, 0, 0.9);
}

void	ft_key_reset(t_map *map)
{
	ft_map_copy(map->copy, map->points, map->width, map->height);
	ft_push_map(map);
}
