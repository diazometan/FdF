/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:38:15 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 15:47:38 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while ((str1[i] == str2[i]) && (str1[i] != '\0' || str2[i] != '\0'))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
