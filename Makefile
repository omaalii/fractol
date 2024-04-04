# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 16:54:02 by omaali            #+#    #+#              #
#    Updated: 2024/04/04 16:58:28 by omaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror -Imlx

SRC = src/main.c src/init.c src/math_utils.c src/string_utils.c \
		src/render.c src/events.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

MAC_FLAGS = -framework OpenGL -framework AppKit
LIB_PATH = ./mlx/
MLX_PATH = $(LIB_PATH)/libmlx.a

FLAGS = -I $(LIB_PATH) -I includes/fractol.h $(CFLAGS)

all : _mlx $(NAME)

$(NAME) : $(OBJECTS) $(MLX_PATH) includes/fractol.h Makefile
	$(CC) $(FLAGS) $(OBJECTS) $(MLX_PATH) $(MAC_FLAGS) -o $(NAME)

%.o : %.c includes/fractol.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean :
	make clean -C $(LIB_PATH)
	rm -f $(OBJECTS)

fclean : clean
	make clean -C $(LIB_PATH)
	rm -f $(NAME)

re : fclean all

_mlx :
	make -C $(LIB_PATH)

.PHONY: all clean fclean re _mlx
