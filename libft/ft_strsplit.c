/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:27:50 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/29 22:38:47 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **s, int i)
{
	while (--i)
		free(s[i]);
	free(s);
}

static int	ft_wordlen(char const *s, char c, int num)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[num] == c)
		num++;
	while (s[num] != c && s[num])
	{
		num++;
		j++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || !(tmp = (char**)malloc(sizeof(char *) * ft_word(s, c) + 1)))
		return (NULL);
	while (j < ft_word(s, c))
	{
		if (!(tmp[j] = (char *)malloc(sizeof(char) * ft_wordlen(s, c, i) + 1)))
		{
			ft_free(tmp, j);
			return (NULL);
		}
		while (s[i] == c)
			i++;
		k = 0;
		while (s[i] != c && s[i])
			tmp[j][k++] = s[i++];
		tmp[j++][k] = '\0';
	}
	tmp[j] = NULL;
	return (tmp);
}
