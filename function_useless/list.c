/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:45:21 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/12 13:10:36 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_coord *ft_pop(t_coord **head)
{
    t_coord *tmp;

    tmp = *head;
    *head = (*head)->next;
    return (tmp);
}

static void ft_push_back(t_coord **head, t_coord *new)
{
    t_coord *tmp;

    if (*head == NULL)
        *head = new;
    else
    {
        tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

static t_coord *ft_create_list(char *line)
{
    t_coord *new;
    char **tmp;
    int a;

    if(!(new = (t_coord*)malloc(sizeof(t_coord))))
        exit (1);
    if (!(tmp = ft_strsplit(line, ',')))
        exit(1);
    new->z = ft_atoi(tmp[0]);   
    new->color = ft_atoi_base(tmp[1], 16);
    new->next = NULL;
    return (new);
}

void ft_stack(char **line, t_coord **coord, t_mlx *mlx)
{
    int width;

    width = 0;
    while (*line)
    {
        ft_push_back(coord, ft_create_list(*(line++)));
        width++;
    }
    mlx->map->width = width;
}

void ft_create_array(t_coord **coord_stack, t_mlx *mlx)
{
    t_coord *coord;
    size_t size;
    size_t i;

    i = 0;
    size = mlx->map->heigth * mlx->map->width;
    mlx->map->coord_z = (int*)malloc(sizeof(int) * size);
    mlx->map->coord_color = (int*)malloc(sizeof(int) * size);
    while (i < size && (coord = ft_pop(coord_stack)))
    {
        mlx->map->coord_z[i] = coord->z;
        mlx->map->coord_color[i] = coord->color;
        if (mlx->map->z_max < coord->z)
            mlx->map->z_max = coord->z;
        if (mlx->map->z_min > coord->z)
            mlx->map->z_min = coord->z;
        free(coord);
        i++;
    }
}

/*void ft_read_map(int fd, t_mlx *mlx)
{
    int check;
    char **info;
    char *line;
    int height;
    t_coord *coord;

    coord = NULL;
    height = 0;
    while ((check = get_next_line(fd, &line)) == 1)
    {
        info = ft_strsplit(line, ' ');
        ft_stack(info, &coord, mlx);
        ft_free(info, 2);
        ft_strdel(&line);
        height++;
    }
    mlx->map->heigth = height;
    ft_init_map(mlx);
    ft_create_array(&coord, mlx);
}*/