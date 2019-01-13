/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:50:08 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/11/29 22:22:00 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list **begin)
{
	t_list	*tmp;

	if (begin)
	{
		while (begin)
		{
			tmp = (*begin)->next;
			free(*begin);
			*begin = tmp;
		}
	}
	*begin = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst && !f && !(tmp = ft_lstnew(NULL, 0)))
		return (NULL);
	tmp = (*f)(lst);
	start = tmp;
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			tmp->next = (*f)(lst);
			if ((tmp->next) == NULL)
			{
				ft_free(&start);
				return (NULL);
			}
			tmp = tmp->next;
		}
	}
	return (start);
}
