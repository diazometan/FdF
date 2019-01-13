/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:48:57 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 14:39:02 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_check_x(t_mlx *mlx)
{
	if ((mlx->line->x_i <= 0 || mlx->line->x_i >= WIN_WIDTH ||
		(int)ROUNDF(mlx->line->y_f) <= MENU_HEIGHT ||
			(int)ROUNDF(mlx->line->y_f) >= WIN_HEIGHT))
		return (0);
	return (1);
}

static int	ft_check_y(t_mlx *mlx)
{
	if (((int)ROUNDF(mlx->line->x_f) <= 0 ||
		(int)ROUNDF(mlx->line->x_f) >= WIN_WIDTH ||
			mlx->line->y_i <= MENU_HEIGHT || mlx->line->y_i >= WIN_HEIGHT))
		return (0);
	return (1);
}

static void	ft_draw_line(t_mlx *mlx)
{
	mlx->line->length++;
	if (mlx->line->length_y <= mlx->line->length_x)
	{
		while ((mlx->line->length)--)
		{
			if (ft_check_x(mlx) == 1)
				mlx->img.data[(int)(mlx->line->x_i + WIN_WIDTH *
					(int)ROUNDF(mlx->line->y_f))] = get_color(mlx);
			mlx->line->x_i += mlx->line->dx;
			mlx->line->y_f += mlx->line->dy *
				(float)mlx->line->length_y / mlx->line->length_x;
		}
	}
	else
	{
		while ((mlx->line->length)--)
		{
			if (ft_check_y(mlx) == 1)
				mlx->img.data[(int)(ROUNDF(mlx->line->x_f) +
					WIN_WIDTH * mlx->line->y_i)] = get_color(mlx);
			mlx->line->x_f += mlx->line->dx *
				(float)mlx->line->length_x / mlx->line->length_y;
			mlx->line->y_i += mlx->line->dy;
		}
	}
}

static void	ft_line(int x2, int y2, t_mlx *mlx, int color)
{
	if (!(mlx->color_start = (t_xyz*)malloc(sizeof(t_xyz))))
		exit(1);
	if (!(mlx->color_end = (t_xyz*)malloc(sizeof(t_xyz))))
		exit(1);
	mlx->color_start->x = mlx->head->x;
	mlx->color_start->y = mlx->head->y;
	mlx->color_start->color = mlx->head->color;
	mlx->color_end->x = x2;
	mlx->color_end->y = y2;
	mlx->color_end->color = color;
	if ((sqrt(x2 - mlx->head->x) * (x2 - mlx->head->x) +
			(y2 - mlx->head->y) * (y2 - mlx->head->y)) < 2)
		return ;
	mlx->line = ft_init_ft_line(mlx->head->x, mlx->head->y, x2, y2);
	if (mlx->line->length == 0)
	{
		mlx->img.data[mlx->head->x +
			WIN_WIDTH * mlx->head->y] = get_color(mlx);
		return ;
	}
	ft_draw_line(mlx);
}

void		draw(t_mlx *mlx)
{
	mlx->map->y = 0;
	while (mlx->map->y < mlx->map->heigth)
	{
		mlx->map->x = 0;
		while (mlx->map->x < mlx->map->width)
		{
			mlx->head = ft_init_xyz(mlx->map->x, mlx->map->y, mlx);
			ft_rotaition(mlx->map, mlx->head);
			if (mlx->map->x != mlx->map->width - 1)
			{
				mlx->tmp = ft_init_xyz(mlx->map->x + 1, mlx->map->y, mlx);
				ft_rotaition(mlx->map, mlx->tmp);
				ft_line(mlx->tmp->x, mlx->tmp->y, mlx, mlx->tmp->color);
			}
			if (mlx->map->y != mlx->map->heigth - 1)
			{
				mlx->cur = ft_init_xyz(mlx->map->x, mlx->map->y + 1, mlx);
				ft_rotaition(mlx->map, mlx->cur);
				ft_line(mlx->cur->x, mlx->cur->y, mlx, mlx->cur->color);
			}
			(mlx->map->x)++;
		}
		(mlx->map->y)++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}
