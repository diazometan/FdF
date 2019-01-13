/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:51:53 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 16:04:01 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	tmp = NULL;
	if (s)
		while (s[j] != '\0')
			j++;
	if (!s || !(tmp = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	if (f)
		while (s[i] != '\0')
		{
			tmp[i] = (*f)(i, s[i]);
			i++;
		}
	tmp[i] = '\0';
	return (tmp);
}
