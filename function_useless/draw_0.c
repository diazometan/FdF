/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:29:25 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 17:34:05 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//формула вычисления позиции пикселя X + 4 * Line_size * Y

#include "header.h"

#define roundf(x) floor(x + 0.5f)
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int key_press(int key, void *param)
{
    if (key == 53)
        exit(1);
    return (0);
}

int exit_x(void)
{
    exit(1);
}

void line(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
    t_draw line;

    line.dx = (x2 - x1 >= 0 ? 1 : -1);
    line.dy = (y2 - y1 >= 0 ? 1 : -1);
    line.lengthX = abs(x2 - x1);
    line.lengthY = abs(y2 - y1);
    line.length = MAX(line.lengthX, line.lengthY);

    if (line.length == 0)
        mlx->img.data[x1 + WIN_WIDTH * y1] = 0xC5F442;
    if (line.lengthY <= line.lengthX)
    {
        line.x_i = x1;
        line.y_f = y1;
        line.length++;
        while (line.length--)
        {
            mlx->img.data[(int)(line.x_i + WIN_WIDTH * roundf(line.y_f))] = 0xC5F442;
            line.x_i += line.dx;
            line.y_f += line.dy * (float)line.lengthY / line.lengthX;
        }
    }
    else
    {
        line.x_f = x1;
        line.y_i = y1;
        line.length++;
        while (line.length--) 
        {
            mlx->img.data[(int)(roundf(line.x_f) + WIN_WIDTH * line.y_i)] = 0xC5F442;
            line.x_f += line.dx * (float)line.lengthX / line.lengthY;
            line.y_i += line.dy;
        }
    }
}

static void x_rotate(int *y, int *z, float alpha)
{
    int pre_y;
    int pre_z;

    pre_y = *y;
    pre_z = *z;
    *y = pre_y * cos(alpha) + pre_z * sin(alpha);
    *z = -pre_y * sin(alpha) + pre_z * cos(alpha);
}

static void y_rotate(int *x, int *z, float beta)
{
    int pre_x;
    int pre_z;

    pre_x = *x;
    pre_z = *z;
    *x = pre_x * cos(beta) + pre_z * sin(beta);
    *z = -pre_x * sin(beta) + pre_z * cos(beta);
}

static void z_rotate(int *x, int *y, float gamma)
{
    int pre_x;
    int pre_y;

    pre_x = *x;
    pre_y = *y;
    *x = pre_x * cos(gamma) - pre_y * sin(gamma);
    *y = pre_x * sin(gamma) + pre_y * cos(gamma);
}

static void iso(int *x, int *y, int z)
{
    int pre_x;
    int pre_y;

    pre_x = *x;
    pre_y = *y;
    *x = (pre_x - pre_y) * cos(0.523599);
    *y = -z + (pre_x + pre_y) * sin(0.523599);
}

int main()
{
    t_mlx mlx;
    int x;
    int y;
    int x1;
    int y1;

    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx");
    mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
    //line(0, 0, 50, 0, &mlx);
    //line(50, 0, 50, 50, &mlx);
    //line(50, 50, 0, 50, &mlx);
    //line(0, 50, 0, 0, &mlx);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
    mlx_key_hook(mlx.win_ptr, key_press, (void *)0);     //закрыть esc
    mlx_hook(mlx.win_ptr, 17, 1L << 17, exit_x, &mlx);   //закрыть мышкой
    mlx_loop(mlx.mlx_ptr);
    return (0);
}


/*void draw(t_mlx *mlx)
{
    int a;
    int b;
    int c;
    int a_1;
    int b_1;
    int c_1;
    int c_2;
    int index;
    int index1;
    int index2;
    int x_0;
    int y_0;
    t_xyz *head;
    t_xyz *tmp;
    t_xyz *cur;

    x_0 = (WIN_WIDTH - map->width) / 2;
    y_0 = (WIN_HEIGHT - map->heigth)/ 2;
	ft_bzero((void *)mlx->img.data, WIN_HEIGHT * WIN_WIDTH * 4);
	mlx->map->y = 0;
    while (mlx->map->y < mlx->map->heigth)
    {
        mlx->map->x = 0;
        while (mlx->map->x < mlx->map->width)
        {
            mlx->head = ft_init_xyz(mlx->map->x, mlx->map->y, mlx);
            ft_rotaition(mlx->map, mlx->head);
            a = 60 * x;
            a = a - (map->width *  60) / 2;
            b = 60 * y;
            b = b - (map->heigth * 60) / 2;
            index = get_index(map, x, y);
            index1 = get_index(map, x + 1, y);
            index2 = get_index(map, x, y + 1);
            c = 10 * map->coord_z[index];
            c_1 = 10 * map->coord_z[index1];
            c_2 = 10 * map->coord_z[index2];
            a_1 = a + 60;
            b_1 = b + 60;
            if (mlx->map->x != mlx->map->width - 1)
            {
                int pre_x = a;
                int pre_y = b;
                int new_x_1 = a_1;
                int rot_1;
                int rot_2;
                int rot_3;
                int rot_4;

                rot_1 = (pre_x - pre_y) * cos(0.523599);
                rot_2 = -c + (pre_x + pre_y) * sin(0.523599);
                rot_3 = (new_x_1 - pre_y) * cos(0.523599);
                rot_4 = -c_1 + (new_x_1 + pre_y) * sin(0.523599);
                mlx->tmp = ft_init_xyz(mlx->map->x + 1, mlx->map->y, mlx);
                ft_rotaition(mlx->map, mlx->tmp);
                ft_line(mlx->head->x_0, mlx->head->y_0, mlx->tmp->x_0, mlx->tmp->y_0, mlx);
            }
            if (mlx->map->y != mlx->map->heigth - 1)
            {
                int pre_x = a;
                int pre_y = b;
                int new_y_1 = b_1;
                int rot_1;
                int rot_2;
                int rot_3;
                int rot_4;

                rot_1 = (pre_x - pre_y) * cos(0.523599);
                rot_2 = -c + (pre_x + pre_y) * sin(0.523599);
                rot_3 = (pre_x - new_y_1) * cos(0.523599);
                rot_4 = -c_2 + (pre_x + new_y_1) * sin(0.523599);
                mlx->cur = ft_init_xyz(mlx->map->x, mlx->map->y + 1, mlx);
                ft_rotaition(mlx->map, mlx->cur);
                ft_line(mlx->head->x_0, mlx->head->y_0, mlx->cur->x_0, mlx->cur->y_0, mlx);
            }
            (mlx->map->x)++;
        }
        (mlx->map->y)++;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}*/