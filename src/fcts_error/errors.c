/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:17:08 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 22:16:37 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_print_content_error(void)
{
	write(2, "Invalid file content.\nPlease verify each", 41);
	write(2, " element has the following format:\n", 36);
	write(2, "\"[decimal number]\" or \n\"[decimal number]", 41);
	write(2, ",[hex number with lenght = 6/8 and 0x prefix]\"\n", 48);
}

static void	ft_print_line_error(void)
{
	write(2, "Error. One or multiple lines do not", 36);
	write(2, " contain the same amount of elements\n", 38);
}

void	ft_error(t_map *map, char name)
{
	if (name == 'e')
		write(2, "Extension error, please use a \".fdf\" file\n", 43);
	if (name == 'l')
		ft_print_line_error();
	if (name == 'c')
		ft_print_content_error();
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
