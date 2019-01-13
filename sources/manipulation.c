/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:24:32 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/12 18:25:30 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == NUM_PAD_PLUS || key == MOUSE_SCROLL_DOWN)
		mlx->map->zoom += 2;
	if (key == NUM_PAD_MINUS || key == MOUSE_SCROLL_UP)
		mlx->map->zoom -= 2;
	if (mlx->map->zoom < 1)
		mlx->map->zoom = 1;
	ft_create_image(mlx);
}

void	ft_angle(int key, t_mlx *mlx)
{
	if (key == NUM_PAD_SEVEN)
		mlx->map->alpha += 10;
	if (key == NUM_PAD_EIGHT)
		mlx->map->beta += 10;
	if (key == NUM_PAD_NINE)
		mlx->map->gamma += 10;
	if (key == NUM_PAD_ONE)
		mlx->map->alpha -= 10;
	if (key == NUM_PAD_TWO)
		mlx->map->beta -= 10;
	if (key == NUM_PAD_THREE)
		mlx->map->gamma -= 10;
	if (key == NUM_PAD_FIVE)
	{
		mlx->map->alpha = 0;
		mlx->map->beta = 0;
		mlx->map->gamma = 0;
	}
	ft_create_image(mlx);
}

void	ft_flatten(int key, t_mlx *mlx)
{
	if (key == NUM_PAD_SIX)
		mlx->map->z_zoom += 0.5;
	if (key == NUM_PAD_FOUR)
		mlx->map->z_zoom -= 0.5;
	if (mlx->map->z_zoom < 0.5)
		mlx->map->z_zoom = 0.0;
	if (mlx->map->z_zoom > 10)
		mlx->map->z_zoom = 10.0;
	ft_create_image(mlx);
}

void	ft_projection(int key, t_mlx *mlx)
{
	if (key == KEYBOARD_ONE)
		mlx->map->projection = PARALLEL;
	if (key == KEYBOARD_TWO)
		mlx->map->projection = ISO;
	if (key == KEYBOARD_THREE)
		mlx->map->projection = PERSPECTIVE;
	ft_create_image(mlx);
}

void	ft_offset(int key, t_mlx *mlx)
{
	if (key == KEYBOARD_LEFT)
		mlx->map->x_offset -= 50;
	if (key == KEYBOARD_RIGHT)
		mlx->map->x_offset += 50;
	if (key == KEYBOARD_DOWN)
		mlx->map->y_offset += 50;
	if (key == KEYBOARD_UP)
		mlx->map->y_offset -= 50;
	if (key == NUM_PAD_FIVE)
	{
		mlx->map->x_offset = 0;
		mlx->map->y_offset = 0;
	}
	ft_create_image(mlx);
}
