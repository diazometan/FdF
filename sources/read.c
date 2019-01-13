/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:29:10 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 17:41:33 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_init_array(t_mlx *mlx)
{
	int		size;

	size = mlx->map->heigth * mlx->map->width;
	if (size == 0)
		exit(1);
	mlx->map->coord_z = (int*)malloc(sizeof(int) * size);
	mlx->map->coord_color = (int*)malloc(sizeof(int) * size);
}

void		ft_read_width(int fd, t_mlx *mlx)
{
	char	*line;
	int		width;
	char	**info;

	width = 0;
	info = NULL;
	if (!(get_next_line(fd, &line) == 1))
		exit(1);
	if (!(info = ft_strsplit(line, ' ')))
		exit(1);
	while (*info)
	{
		info++;
		width++;
	}
	mlx->map->width = width;
}

void		ft_read_heigth(int fd, t_mlx *mlx)
{
	int		check;
	char	*line;
	int		height;

	height = 1;
	while ((check = get_next_line(fd, &line)) == 1)
	{
		ft_strdel(&line);
		height++;
	}
	mlx->map->heigth = height;
}

void		ft_create_array(t_mlx *mlx, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**tmp;
	char	**info;

	i = 0;
	ft_init_array(mlx);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		j = 0;
		while (tmp[j])
		{
			info = ft_strsplit(tmp[j], ',');
			mlx->map->coord_z[i] = ft_atoi(info[0]);
			mlx->map->coord_color[i] = ft_atoi_base(info[1], 16);
			if (mlx->map->z_max < mlx->map->coord_z[i])
				mlx->map->z_max = mlx->map->coord_z[i];
			if (mlx->map->z_min > mlx->map->coord_z[i])
				mlx->map->z_min = mlx->map->coord_z[i];
			i++;
			j++;
		}
	}
}

void		ft_read_map(int fd, t_mlx *mlx, char **argv)
{
	ft_read_width(fd, mlx);
	ft_read_heigth(fd, mlx);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	ft_init_map(mlx);
	ft_create_array(mlx, fd);
}
