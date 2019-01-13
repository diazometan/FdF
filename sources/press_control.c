/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:01:42 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/12 14:42:07 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEYBOARD_ESC)
		exit(1);
	if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		ft_zoom(key, mlx);
	if (key == NUM_PAD_SEVEN || key == NUM_PAD_EIGHT || key == NUM_PAD_NINE ||
		key == NUM_PAD_ONE || key == NUM_PAD_TWO ||
			key == NUM_PAD_THREE || key == NUM_PAD_FIVE)
		ft_angle(key, mlx);
	if (key == NUM_PAD_FOUR || key == NUM_PAD_SIX)
		ft_flatten(key, mlx);
	if (key == KEYBOARD_ONE || key == KEYBOARD_TWO || key == KEYBOARD_THREE)
		ft_projection(key, mlx);
	if (key == KEYBOARD_LEFT || key == KEYBOARD_RIGHT ||
		key == KEYBOARD_DOWN || key == KEYBOARD_UP || key == NUM_PAD_FIVE)
		ft_offset(key, mlx);
	return (0);
}

int	mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return (0);
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		ft_zoom(button, mlx);
	else if (button == MOUSE_BUTTON_1)
		mlx->mouse->press_1 = 1;
	else if (button == MOUSE_BUTTON_2)
		mlx->mouse->press_2 = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_mlx *mlx)
{
	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return (0);
	(void)button;
	mlx->mouse->press_1 = 0;
	mlx->mouse->press_2 = 0;
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->pre_x = mlx->mouse->x;
	mlx->mouse->pre_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->press_1 == 1)
	{
		mlx->map->beta += (x - mlx->mouse->pre_x) * 0.5;
		mlx->map->alpha += (y - mlx->mouse->pre_y) * 0.5;
		ft_create_image(mlx);
	}
	if (mlx->mouse->press_2 == 1)
	{
		mlx->map->x_offset += (x - mlx->mouse->pre_x);
		mlx->map->y_offset += (y - mlx->mouse->pre_y);
		ft_create_image(mlx);
	}
	return (0);
}

int	exit_x(void)
{
	exit(1);
}
