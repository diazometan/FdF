/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:16:56 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/12/02 17:19:20 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strrev(char *str)
{
	int		i;
	int		j;
	int		l;
	char	t;

	l = ft_strlen(str);
	i = 0;
	j = l - 1;
	while (i < j)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
		i++;
		j--;
	}
}
