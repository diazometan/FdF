/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:03:06 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 18:00:17 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			get_index(t_map *map, int x, int y)
{
	return (x + y * map->width);
}

float		ft_radian(int degree)
{
	float	radian;

	radian = degree * 3.14 / 180;
	return (radian);
}

int			ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void		ft_create_image(t_mlx *mlx)
{
	ft_bzero((void *)mlx->img.data, WIN_HEIGHT * WIN_WIDTH * 4);
	ft_draw_back(mlx);
	ft_draw_head(mlx);
	draw(mlx);
	ft_menu(mlx);
}