/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_key_actions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:19:56 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/03 11:17:03 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_key_save(t_map *map)
{
	ft_map_copy(map->points, map->copy, map->width, map->height);
	ft_push_map(map);
}

void	ft_key_switch_proj(t_map *map, int keycode)
{
	if (keycode == 18)
		map->proj = 'i';
	if (keycode == 19)
		map->proj = 'o';
	if (keycode == 20)
		map->proj = 'p';
	if (keycode == 21)
		map->proj = 't';
	ft_push_map(map);
}
