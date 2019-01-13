/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:25:36 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 15:35:53 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;

	a = (unsigned char*)s;
	while (n--)
	{
		if (*a == (unsigned char)c)
			return (void *)a;
		a++;
	}
	return (NULL);
}
