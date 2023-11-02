/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/02 16:14:42 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define PI 3.14159265358979323846
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	int				proj_x;
	int				proj_y;
	int				col;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
	int		screen_w;
	int		screen_h;
	t_mlx	mlx;
	t_data	img;
}	t_map;

typedef struct s_file
{
	int		fd;
	char	*buf;
}	t_file;

//gnl_functions
char	*get_next_line(int fd);
char	*ft_read_line(char *buf, int fd);
char	*ft_crop_buf(char *buf);
char	*ft_get_cropped(char *buf);
//gln_utils
int		ft_find(char *s, int mod);
char	*ft_calloc(int size);
char	*ft_strndup(char *src, int max);
char	*ft_strjoin(char *buf, char *to_add);
//
//mlx_utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_start(t_map *map);
int		ft_end(t_map *map);
//
//map
t_map	*ft_get_map(char *file, int screen_w, int screen_h);
//map_utils
void	ft_free_map(t_map *map);
void	ft_minmax(t_point *min, t_point *max, t_point *current);
double	ft_get_scale_factor(t_map *map);
//
//draw_map
void	ft_draw_map(t_map *map);
//projection
void	ft_project(t_map *map, char proj);
//
//transfo_unit
void	ft_rotate_u(t_point *point, double angle, char axis);
void	ft_translate_u(t_point *point, double mv_x, double mv_y, double mv_z);
void	ft_scale_u(t_point *point, double factor, char axis);
//transformations
void	ft_rotate(t_map *map, double angle, char axis);
void	ft_translate(t_map *map, double mv_x, double mv_y, double mv_z);
void	ft_scale(t_map *map, double x, double y, double z);
void	ft_center(t_map *map);
//key_transformations
void	ft_key_rotate(int keycode, t_map *map);
void	ft_key_translate(int keycode, t_map *map);
void	ft_key_scale(int keycode, t_map *map);
//
//errors
int		ft_error(t_map *map, char name);
//
//utils
char	**ft_split(char const *s, char c);
void	*ft_free_str_tab(char **strs);
char	*ft_strchr(char *s, int c);
int		ft_atoi(char *str);
int		ft_atoi_hexa(char *str);

#endif