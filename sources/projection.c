/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:05:00 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 16:44:07 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	iso(int *x, int *y, int z)
{
	int	pre_x;
	int	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.523599);
	*y = -z + (pre_x + pre_y) * sin(0.523599);
}

void	perspective(int *x, int *y, int *z)
{
	int	pre_x;
	int	pre_y;
	int pre_z;

	pre_x = *x;
	pre_y = *y;
	pre_z = *z;
	*x = pre_x / (-0.0005 * pre_z + 1);
	*y = pre_y / (-0.0005 * pre_z + 1);
	*z = pre_z / (-0.0005 * pre_z + 1);
	if (*x == INT_MIN || *y == INT_MIN || ft_abs(*z) >= WIN_WIDTH)
	{
		*x = pre_x;
		*y = pre_y;
		*z = pre_z;
	}
}
