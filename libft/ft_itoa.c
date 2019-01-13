/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:19:51 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/28 16:37:00 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		flag;

	flag = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_numlen(n);
	if (!(s = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	s[i] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = n * (-1);
		flag = 1;
	}
	while (flag < i--)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}
