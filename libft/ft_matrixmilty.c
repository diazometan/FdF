/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixmilty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 08:15:22 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/12/01 08:32:59 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrixmilty(int **a, int **b, int **c, int n)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c[i][j] = 0;
			while (k < n)
			{
				c[i][j] += a[i][k] * b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}
