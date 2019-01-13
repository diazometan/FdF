# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 16:55:04 by lwyl-the          #+#    #+#              #
#    Updated: 2019/01/13 11:51:56 by lwyl-the         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = minilibx_macos/libmlx.a

LIB = libft/libft.a

SRC = sources/main.c\
	sources/assistant.c\
	sources/color.c\
	sources/draw.c\
	sources/ft_atoi_base.c\
 	sources/get_next_line.c\
	sources/init.c\
	sources/manipulation.c\
	sources/menu.c\
	sources/press_control.c\
	sources/projection.c\
	sources/read.c\
	sources/rotation.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(MLX)
	gcc -o $(NAME) -Llibft -lft $(OBJ) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

.c.o:
	gcc  -Wall -Wextra -Werror -I includes/ -Ilibft -o $@ -c $<

$(LIB):
	cd libft && make
	cd libft && make clean

$(MLX):
	cd minilibx_macos && make

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean
	cd minilibx_macos && make clean

re: fclean all