#include "header.h"

int			ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int			ft_base(int nb, int base)
{
	char	str1[17];
	char	str2[17];
	int		i;

	i = 0;
	str1[17] = "0123456789abcdef";
	str2[17] = "0123456789ABCDEF";
	while (i < base)
	{
		if (nb == str1[i] || nb == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, int base)
{
	int		result;
	int		i;
	int		flag;

	result = 0;
	i = 0;
	flag = 0;
	if (str == NULL)
		return (0);
	while (ft_iswhitespace(str[i]))
		i++;
	if (base == 16)
		i += 2;
	if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				flag = 1;
			i++;
		}
	while (ft_base(str[i], base) != -1)
	{
		result = result * base + ft_base(str[i], base);
		i++;
	}
	if (flag == 1)
		result = result * (-1);
	return (result);
}