/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:41:43 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/12/02 17:00:24 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_remalloc(void *ptr, size_t prev_size, size_t new_size)
{
	void	*new;
	size_t	len;

	if (!ptr)
		return (NULL);
	if (!(new = ft_memalloc(new_size)))
	{
		free(ptr);
		return (NULL);
	}
	len = prev_size < new_size ? prev_size : new_size;
	new = ft_memmove(new, ptr, len);
	free(ptr);
	return (new);
}
