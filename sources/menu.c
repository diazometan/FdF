/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:28:15 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/12 20:06:38 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_menu_mouse(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 260, 30,
		0x4169E1, "Mouse button left:        Rotation");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 260, 50,
		0x4169E1, "Mouse button rigth:       Offset");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 260, 70,
		0x4169E1, "Mouse button scroll down: Zoom minus");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 260, 90,
		0x4169E1, "Mouse button scroll up:   Zoom plus");
}

static void		ft_menu_keyboard(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 660, 30,
		0x4169E1, "Keyboard 1:     Parallel projection");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 660, 50,
		0x4169E1, "Keyboard 2:     ISO projection");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 660, 70,
		0x4169E1, "Keyboard 3:     Perspective projection");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 660, 90,
		0x4169E1, "Keyboard left:  Offset left 50");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 660, 110,
		0x4169E1, "Keyboard right: Offset right 50");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 660, 130,
		0x4169E1, "Keyboard up:    Offset up 50");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 660, 150,
		0x4169E1, "Keyboard down:  Offset down 50");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 150,
		0xFF0000, "For escape use: ESC or click on X");
}

static void		ft_menu_keyboard_numpad(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1060, 30,
		0x4169E1, "Numpad 1: Rotation X minus 10 degrees");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1060, 50,
		0x4169E1, "Numpad 2: Rotation Y minus 10 degrees");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1060, 70,
		0x4169E1, "Numpad 3: Rotation Z minus 10 degrees");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1060, 90,
		0x4169E1, "Numpad 4: Z zoom minus");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1060, 110,
		0x4169E1, "Numpad 5: Centre");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1060, 130,
		0x4169E1, "Numpad 6: Z zoom plus");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1460, 30,
		0x4169E1, "Numpad 7: Rotation X plus 10 degrees");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1460, 50,
		0x4169E1, "Numpad 8: Rotation Y plus 10 degrees");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1460, 70,
		0x4169E1, "Numpad 9: Rotation Z plus 10 degrees");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1460, 90,
		0x4169E1, "Numpad +: Zoom plus");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1460, 110,
		0x4169E1, "Numpad -: Zoom minus");
}

void			ft_menu(t_mlx *mlx)
{
	ft_menu_mouse(mlx);
	ft_menu_keyboard(mlx);
	ft_menu_keyboard_numpad(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 30,
		0x4169E1, "Mouse X:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 170, 30,
		0x4169E1, ft_itoa(mlx->mouse->x));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 50,
		0x4169E1, "Mouse Y:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 170, 50,
		0x4169E1, ft_itoa(mlx->mouse->y));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 70,
		0x4169E1, "Rotation X:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 170, 70,
		0x4169E1, ft_itoa(mlx->map->alpha));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 90,
		0x4169E1, "Rotation Y:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 170, 90,
		0x4169E1, ft_itoa(mlx->map->beta));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 110,
		0x4169E1, "Rotation Z:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 170, 110,
		0x4169E1, ft_itoa(mlx->map->gamma));
}
