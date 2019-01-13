/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:17:52 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 15:09:38 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line.h"
# include "../libft/includes/libft.h"
# include "key.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MENU_HEIGHT 200

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define ROUNDF(x) floor(x + 0.5f)

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef enum
{
	ISO,
	PARALLEL,
	PERSPECTIVE
}	t_proj;

typedef struct	s_draw
{
	int			dx;
	int			dy;
	int			length_x;
	int			length_y;
	int			length;
	int			x_i;
	int			y_i;
	float		x_f;
	float		y_f;
}				t_draw;

typedef struct	s_xyz
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_xyz;

typedef struct	s_map
{
	int			heigth;
	int			width;
	int			*coord_z;
	int			*coord_color;
	int			z_max;
	int			z_min;
	int			zoom;
	float		z_zoom;
	int			x;
	int			y;
	int			x_offset;
	int			y_offset;
	int			alpha;
	int			beta;
	int			gamma;
	t_proj		projection;
}				t_map;

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			pre_x;
	int			pre_y;
	int			press_1;
	int			press_2;
}				t_mouse;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			*buffer;
	t_img		img;
	t_xyz		*new;
	t_xyz		*head;
	t_xyz		*tmp;
	t_xyz		*cur;
	t_xyz		*color_start;
	t_xyz		*color_end;
	t_map		*map;
	t_mouse		*mouse;
	t_draw		*line;
}				t_mlx;

void			ft_create_array(t_mlx *mlx, int fd);
t_xyz			*ft_init_xyz(int x, int y, t_mlx *mlx);
t_draw			*ft_init_ft_line(int x1, int y1, int x2, int y2);
void			ft_init_map(t_mlx *mlx);
void			ft_init_mlx(t_mlx *mlx);
void			ft_init_key(t_mlx *mlx);

int				key_press(int key, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				mouse_release(int button, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);
int				exit_x(void);

void			ft_zoom(int key, t_mlx *mlx);
void			ft_angle(int key, t_mlx *mlx);
void			ft_flatten(int key, t_mlx *mlx);
void			ft_projection(int key, t_mlx *mlx);
void			ft_offset(int key, t_mlx *mlx);
void			ft_read_map(int fd, t_mlx *mlx, char **argv);
void			ft_rotaition(t_map *map, t_xyz *head);

int				get_default_color(int z, t_map *map);
int				get_color(t_mlx *mlx);
void			ft_menu(t_mlx *mlx);
void			ft_draw_back(t_mlx *mlx);
void			ft_draw_head(t_mlx *mlx);
void			draw(t_mlx *mlx);
void			ft_create_image(t_mlx *mlx);

int				get_index(t_map *map, int x, int y);
int				ft_abs(int a);
int				ft_atoi_base(char *str, int base);
float			ft_radian(int degree);

void			iso(int *x, int *y, int z);
void			perspective(int *x, int *y, int *z);

#endif
