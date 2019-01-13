/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:13:41 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/30 00:14:27 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*last;

	i = 0;
	j = 0;
	last = NULL;
	while (s[i] != '\0')
		i++;
	i++;
	while (j < i)
	{
		if (s[j] == (char)c)
			last = (char *)(&s[j]);
		j++;
	}
	return (last);
}
