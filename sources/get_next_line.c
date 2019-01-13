/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:28:27 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/07 12:00:35 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list			*ft_check_list(t_list **list, int fd)
{
	t_list				*tmp;
	t_info				file;

	tmp = *list;
	while (tmp)
	{
		if (((t_info *)(tmp->content))->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	file.fd = fd;
	file.str = ft_strnew(1);
	file.start = file.str;
	if (!(tmp = ft_lstnew((void*)&file, sizeof(t_info))))
		return (NULL);
	ft_lstadd(list, tmp);
	tmp = *list;
	return (tmp);
}

static char				*ft_make_line(char **str)
{
	char				*line;
	size_t				len;

	if (ft_strchr(*str, '\n'))
	{
		len = ft_strchr(*str, '\n') - *str;
		line = ft_strsub(*str, 0, len);
		*str = *str + (len + 1);
	}
	else
	{
		len = ft_strlen(*str);
		line = ft_strsub(*str, 0, len);
		*str = *str + len;
	}
	return (line);
}

int						get_next_line(const int fd, char **line)
{
	int					ret;
	char				buf[BUFF_SIZE + 1];
	static t_list		*list;
	t_list				*tmp;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	tmp = ft_check_list(&list, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		CONTENT(tmp) = ft_strjoin(CONTENT(tmp), buf);
		ft_strdel(&(((t_info *)(tmp->content))->start));
		((t_info *)(tmp->content))->start = ((t_info *)(tmp->content))->str;
		if (ft_strchr(((t_info *)(tmp->content))->str, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !(ft_strlen(((t_info *)(tmp->content))->str)))
		return (0);
	*line = ft_make_line(&(((t_info *)(tmp->content))->str));
	return (1);
}
