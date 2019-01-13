/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:22:08 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/12 17:53:56 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double		ft_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			get_color(t_mlx *mlx)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (mlx->color_start->color == mlx->color_end->color)
		return (mlx->color_start->color);
	if (mlx->line->length_x > mlx->line->length_y)
		percentage = ft_percent(mlx->color_start->x,
				mlx->color_end->x, mlx->line->x_i);
	else
		percentage = ft_percent(mlx->color_start->y,
				mlx->color_end->y, mlx->line->y_i);
	red = get_light((mlx->color_start->color >> 16) & 0xFF,
				(mlx->color_end->color >> 16) & 0xFF, percentage);
	green = get_light((mlx->color_start->color >> 8) & 0xFF,
				(mlx->color_end->color >> 8) & 0xFF, percentage);
	blue = get_light(mlx->color_start->color & 0xFF,
				mlx->color_end->color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int			get_default_color(int z, t_map *map)
{
	double	percentage;

	percentage = ft_percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (0x9A1F6A);
	else if (percentage < 0.4)
		return (0xC2294E);
	else if (percentage < 0.6)
		return (0xEC4B27);
	else if (percentage < 0.8)
		return (0xEF8633);
	else
		return (0xF3AF3D);
}
