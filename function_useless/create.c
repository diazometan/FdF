/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 11:57:24 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/06 12:42:36 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int main()
{
    t_mlx mlx;
    int count_w;
    int count_h;
    
    count_h = 0;
    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx");
    mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
    while (count_h < WIN_HEIGHT)
    {
        count_w = 0;
        while (count_w < WIN_WIDTH)
        {
            if (count_w % 4)
                mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xC5F442;
            else
                mlx.img.data[count_h * WIN_WIDTH + count_w] = 0x4277F4;
            count_w++;
        }
        count_h++;
    }
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
    mlx_loop(mlx.mlx_ptr);
}
