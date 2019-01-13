/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:28:36 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/01/13 11:40:13 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1024
# define CONTENT(x) ((t_info *)(x->content))->str

typedef struct		s_info
{
	int				fd;
	char			*str;
	char			*start;
}					t_info;

int					get_next_line(const int fd, char **line);

#endif
