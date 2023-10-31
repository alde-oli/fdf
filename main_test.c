/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:32:21 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/31 17:45:24 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;

	if (argc != 2)
		return (0);
	map = ft_get_map(argv[1], 1920, 1080);
	mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "fdf");
	map->mlx = mlx;
	ft_scale(map, 5, 'z');
	ft_scale(map, 5, 'x');
	ft_scale(map, 5, 'y');
	ft_translate(map, 0, 0, 200);
	ft_rotate(map, PI / 2, 'z');
	ft_project(map, PI / 6);
	ft_draw_map(map);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
