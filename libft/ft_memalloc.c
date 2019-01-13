/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:04:50 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 15:22:23 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*str;

	str = NULL;
	if ((str = malloc(size)) && size != 0)
	{
		ft_bzero(str, size);
		return (str);
	}
	else
		return (NULL);
}
