/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:08:49 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 18:00:28 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_draw_head(t_mlx *mlx)
{
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		mlx->img.data[x + WIN_WIDTH * MENU_HEIGHT] = 0x4169E1;
		x++;
	}
}

void		ft_draw_back(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx->img.data[x + WIN_WIDTH * y] = 0x000000;
			x++;
		}
		y++;
	}
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;

	fd = 0;
	if (!(mlx.map = (t_map*)malloc(sizeof(t_map))))
		exit(1);
	if (!(mlx.mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		exit(1);
	if (argc != 2)
		exit(1);
	if (argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
			exit(1);
	}
	ft_read_map(fd, &mlx, argv);
	ft_init_mlx(&mlx);
	ft_create_image(&mlx);
	ft_init_key(&mlx);
	mlx_loop(mlx.mlx_ptr);
	exit (0);
}
