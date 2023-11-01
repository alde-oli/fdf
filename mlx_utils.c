/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/01 14:58:11 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	printf("%d\n", ft_atoi("1000000000000000000"));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	printf("%d\n", ft_atoi("1000000000000000000"));
	*(unsigned int *)dst = color;
	printf("%d\n", ft_atoi("1000000000000000000"));
}
