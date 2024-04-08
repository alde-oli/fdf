/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:32:21 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:21:58 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_keypress(int keycode, void *map)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		ft_end(map);
	if (keycode == 113 || keycode == 119 || keycode == 101
		|| keycode == 97 || keycode == 115 || keycode == 100)
		ft_key_rotate(keycode, map);
	if (keycode == 112 || keycode == 232 || keycode == 65111
		|| keycode == 233 || keycode == 224 || keycode == 36)
		ft_key_translate(keycode, map);
	if (keycode == 117 || keycode == 105 || keycode == 111
		|| keycode == 106 || keycode == 107 || keycode == 108)
		ft_key_scale(keycode, map);
	if (keycode == 65288)
		ft_key_reset(map);
	if (keycode == 65293)
		ft_key_save(map);
	if (keycode == 32)
		ft_center(map);
	if (keycode >= 49 && keycode <= 52)
		ft_key_switch_proj(map, keycode);
	if (keycode == 167)
		ft_my_little_poney(map);
	if (keycode == 99)
		ft_change_map(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (!(argc == 2 || argc == 4))
	{
		write(2, "Error, please add just one file as argument,\n", 46);
		write(2, "or two more arguments as window dimentions\n", 44);
		return (1);
	}
	ft_check_file(argv[1]);
	if (argc == 2)
		map = ft_get_map(argv[1], 1000, 1000);
	else
		map = ft_get_map(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	if (!map)
		ft_error(map, 'a');
	mlx_hook(map->mlx.win, 17, 0, ft_end, map);
	mlx_hook(map->mlx.win, 2, 1L << 0, ft_keypress, map);
	mlx_loop(map->mlx.mlx);
}
