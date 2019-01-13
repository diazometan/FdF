/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:49 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 15:16:31 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	x_rotate(int *y, int *z, float alpha)
{
	int		pre_y;
	int		pre_z;

	pre_y = *y;
	pre_z = *z;
	*y = pre_y * cos(alpha) + pre_z * sin(alpha);
	*z = -pre_y * sin(alpha) + pre_z * cos(alpha);
}

static void	y_rotate(int *x, int *z, float beta)
{
	int		pre_x;
	int		pre_z;

	pre_x = *x;
	pre_z = *z;
	*x = pre_x * cos(beta) + pre_z * sin(beta);
	*z = -pre_x * sin(beta) + pre_z * cos(beta);
}

static void	z_rotate(int *x, int *y, float gamma)
{
	int		pre_x;
	int		pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x * cos(gamma) - pre_y * sin(gamma);
	*y = pre_x * sin(gamma) + pre_y * cos(gamma);
}

void		ft_rotaition(t_map *map, t_xyz *head)
{
	head->x *= map->zoom;
	head->y *= map->zoom;
	head->z = head->z * map->z_zoom * map->zoom / 30;
	head->x -= (map->zoom * (map->width - 1)) / 2;
	head->y -= (map->zoom * (map->heigth - 1)) / 2;
	x_rotate(&(head->y), &(head->z), ft_radian(map->alpha));
	y_rotate(&(head->x), &(head->z), ft_radian(map->beta));
	z_rotate(&(head->x), &(head->y), ft_radian(map->gamma));
	if (map->projection == ISO)
		iso(&(head->x), &(head->y), head->z);
	if (map->projection == PERSPECTIVE)
		perspective(&(head->x), &(head->y), &(head->z));
	head->x = head->x + map->x_offset + WIN_WIDTH / 2;
	head->y = head->y + map->y_offset + (WIN_HEIGHT + MENU_HEIGHT) / 2;
}
