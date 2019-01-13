/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:52:41 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/12/01 10:59:54 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_src;
	unsigned char	*c_dst;

	c_src = (unsigned char*)src;
	c_dst = (unsigned char*)dst;
	if (c_dst == c_src)
		return (dst);
	if (c_dst <= c_src || c_dst >= (c_src + len))
	{
		while (len--)
			*c_dst++ = *c_src++;
	}
	else
	{
		c_dst += len - 1;
		c_src += len - 1;
		while (len--)
			*c_dst-- = *c_src--;
	}
	return (dst);
}
