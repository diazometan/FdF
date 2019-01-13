/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:21:52 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/12 13:56:48 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int			ft_base(int nb, int base)
{
	char	*str1;
	char	*str2;
	int		i;

	i = 0;
	str1 = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	while (i < base)
	{
		if (nb == str1[i] || nb == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, int base)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (ft_iswhitespace(str[i]))
		i++;
	if (base == 16)
		i += 2;
	while (ft_base(str[i], base) != -1)
	{
		result = result * base + ft_base(str[i], base);
		i++;
	}
	return (result);
}
