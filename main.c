/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:32:21 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/03 14:56:51 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	ft_keypress(int keycode, void *map)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		ft_end(map);
	if ((keycode <= 14 && keycode >= 12) || (keycode <= 2 && keycode >= 0))
		ft_key_rotate(keycode, map);
	if (keycode <= 88 && keycode >= 83)
		ft_key_translate(keycode, map);
	if ((keycode <= 17 && keycode >= 15) || (keycode <= 5 && keycode >= 3))
		ft_key_scale(keycode, map);
	if (keycode == 51)
		ft_key_reset(map);
	if (keycode == 36)
		ft_key_save(map);
	if (keycode == 49)
		ft_center(map);
	if (keycode >= 18 && keycode <= 21)
		ft_key_switch_proj(map, keycode);
	if (keycode == 35)
		ft_my_little_poney(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (0);
	map = ft_get_map(argv[1], 1300, 1300);
	if (!map)
		return (ft_error(map, 'm'));
	mlx_hook(map->mlx.win, 17, 0, ft_end, map);
	mlx_hook(map->mlx.win, 2, 1L << 0, ft_keypress, map);
	mlx_loop(map->mlx.mlx);
}
