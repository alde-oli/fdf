/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:09:31 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:17:18 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_rotate(int keycode, t_map *map)
{
	if (keycode == 113)
		ft_rotate(map, 5, 'x');
	if (keycode == 97)
		ft_rotate(map, -5, 'x');
	if (keycode == 119)
		ft_rotate(map, 5, 'y');
	if (keycode == 115)
		ft_rotate(map, -5, 'y');
	if (keycode == 101)
		ft_rotate(map, 5, 'z');
	if (keycode == 100)
		ft_rotate(map, -5, 'z');
}

void	ft_key_translate(int keycode, t_map *map)
{
	if (keycode == 112)
		ft_translate(map, 5, 0, 0);
	if (keycode == 233)
		ft_translate(map, -5, 0, 0);
	if (keycode == 232)
		ft_translate(map, 0, 5, 0);
	if (keycode == 224)
		ft_translate(map, 0, -5, 0);
	if (keycode == 65111)
		ft_translate(map, 0, 0, 5);
	if (keycode == 36)
		ft_translate(map, 0, 0, -5);
}

void	ft_key_scale(int keycode, t_map *map)
{
	if (keycode == 117)
		ft_scale(map, 1.1, 0, 0);
	if (keycode == 106)
		ft_scale(map, 0.9, 0, 0);
	if (keycode == 105)
		ft_scale(map, 0, 1.1, 0);
	if (keycode == 107)
		ft_scale(map, 0, 0.9, 0);
	if (keycode == 111)
		ft_scale(map, 0, 0, 1.1);
	if (keycode == 108)
		ft_scale(map, 0, 0, 0.9);
}

void	ft_key_reset(t_map *map)
{
	ft_map_copy(map->copy, map->points, map->width, map->height);
	ft_push_map(map);
}
