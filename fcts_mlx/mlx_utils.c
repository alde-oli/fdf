/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/05 16:01:15 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bits_per_pixel - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_start(t_map *map)
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
	if (!map->mlx.mlx || !map->mlx.win || !map->img.img || !map->img.addr)
		ft_error(map, 's');
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
}

int	ft_end(t_map *map)
{
	if (map)
	{
		mlx_destroy_image(map->mlx.mlx, map->img.img);
		mlx_clear_window(map->mlx.mlx, map->mlx.win);
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		ft_free_map(map);
	}
	exit(EXIT_SUCCESS);
}
