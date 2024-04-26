/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:17:08 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/06 09:50:27 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_error(t_map *map, char name)
{
	if (name == 'e')
		write(2, "Extension error, please use a \".fdf\" file\n", 43);
	if (name == 'f')
		perror("Error while opening the file");
	if (name == 'a')
		perror("Error while generating the object");
	if (map)
	{
		mlx_destroy_image(map->mlx.mlx, map->img.img);
		mlx_clear_window(map->mlx.mlx, map->mlx.win);
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		ft_free_map(map);
	}
	exit(EXIT_FAILURE);
}
