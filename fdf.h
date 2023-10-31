/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/31 07:54:56 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define PI 3.14159265358979323846
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

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
//map_get
t_map	*ft_get_map(char *file, int screen_w, int screen_h);
//map_utils
void	ft_free_map(t_map *map);
void	ft_center_map(t_map *map);
//transformations
void	ft_rotate(t_point *point, double angle, char axis);
void	ft_translate(t_point *point, double mv_x, double mv_y, double mv_z);
void	ft_scale(t_point *point, double factor, char axis);
//utils
char	**ft_split(char const *s, char c);
void	*ft_free_str_tab(char **strs);
char	*ft_strchr(char *s, int c);
int		ft_atoi(char *str);
int		ft_atoi_hexa(char *str);


#endif