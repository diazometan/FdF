/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:41:52 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 16:05:39 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (str1[i] != '\0'
				|| str2[i] != '\0') && n > 1)
	{
		i++;
		n--;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
