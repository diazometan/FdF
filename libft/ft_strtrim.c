/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:43:03 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 19:09:50 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = i;
	while (s[i] != '\0')
		i++;
	if (i > 0)
		i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		if (i == 0)
		{
			tmp = ft_strnew(i + 1);
			return (tmp);
		}
		i--;
	}
	tmp = ft_strsub(s, j, (size_t)(i - j + 1));
	return (tmp);
}
