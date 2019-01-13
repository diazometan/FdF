/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:11:33 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 15:24:15 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	while (n--)
	{
		if (*a == (unsigned char)c)
		{
			*b = (unsigned char)c;
			b++;
			return (b);
		}
		*b++ = *a++;
	}
	return (NULL);
}
