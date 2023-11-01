/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:32:21 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/01 14:50:37 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_map(t_map *map)
{
	int	i;
	int	j;
	t_point	*pt;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			pt = &(map->points[i][j]);
			printf("P[%d][%d]: 3D = [x:%f, y:%f, z:%f] ; proj = [x: %d, y: %d] ; col = %#X\n", i, j, pt->x, pt->y, pt->z, pt->proj_x, pt->proj_y, pt->col);
			j++;
		}
		i++;
	}
}

void	ft_start_mlx(t_map *map)
{
	t_mlx	mlx;
	t_data	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, map->screen_w,
			map->screen_h, "fdf");
	img.img = mlx_new_image(mlx.mlx, map->screen_w, map->screen_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	map->mlx = mlx;
	map->img = img;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (0);
	map = ft_get_map(argv[1], 1920, 1080);
	ft_start_mlx(map);
	ft_translate(map, -(map->width / 2), -(map->height / 2), 0);
	ft_scale(map, 3, 'x');
	ft_scale(map, 3, 'y');
	ft_scale(map, 1, 'z');
	ft_project(map, PI / 6);
	ft_draw_map(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
	mlx_loop(map->mlx.mlx);
	return (0);
}
