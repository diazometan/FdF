/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:08:14 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 16:10:33 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*s2))
		return (char *)s1;
	if (!len)
		return (NULL);
	while (s1[i] != '\0' && (i != (len)))
	{
		j = 0;
		while (s2[j] == s1[i + j] && ((i + j) != len))
		{
			if (s2[j + 1] == '\0')
				return (char *)&s1[i];
			j++;
		}
		i++;
	}
	return (NULL);
}
