/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:23:07 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 16:02:38 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;
	int		j;

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
			tmp[i] = (*f)(s[i]);
			i++;
		}
	tmp[i] = '\0';
	return (tmp);
}
