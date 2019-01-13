/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:52:11 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/12 20:27:43 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_draw	*ft_init_ft_line(int x1, int y1, int x2, int y2)
{
	t_draw *line;

	if (!(line = (t_draw *)malloc(sizeof(t_draw))))
		exit(1);
	line->dx = (x2 - x1 >= 0 ? 1 : -1);
	line->dy = (y2 - y1 >= 0 ? 1 : -1);
	line->length_x = ft_abs(x2 - x1);
	line->length_y = ft_abs(y2 - y1);
	line->length = MAX(line->length_x, line->length_y);
	line->x_i = x1;
	line->y_f = y1;
	line->x_f = x1;
	line->y_i = y1;
	return (line);
}

void	ft_init_map(t_mlx *mlx)
{
	mlx->mouse->x = 0;
	mlx->mouse->y = 0;
	mlx->map->z_max = INT_MIN;
	mlx->map->z_min = INT_MAX;
	mlx->map->alpha = 0;
	mlx->map->beta = 0;
	mlx->map->gamma = 0;
	mlx->map->z_zoom = 1;
	mlx->map->x_offset = 0;
	mlx->map->y_offset = 0;
	mlx->map->projection = PARALLEL;
	mlx->map->zoom = MIN((WIN_WIDTH / mlx->map->width) / 2,
		((WIN_HEIGHT + MENU_HEIGHT) / mlx->map->heigth) / 2);
}

t_xyz	*ft_init_xyz(int x, int y, t_mlx *mlx)
{
	int	index;

	if (!(mlx->new = (t_xyz *)malloc(sizeof(t_xyz))))
		exit(1);
	mlx->new->x = x;
	mlx->new->y = y;
	index = get_index(mlx->map, x, y);
	mlx->new->z = mlx->map->coord_z[index];
	if (mlx->map->coord_color[index] == 0)
		mlx->new->color = get_default_color(mlx->new->z, mlx->map);
	else
		mlx->new->color = mlx->map->coord_color[index];
	return (mlx->new);
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
		&mlx->img.size_l, &mlx->img.endian);
}

void	ft_init_key(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, exit_x, mlx);
}
