# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 14:49:52 by melmarti          #+#    #+#              #
#    Updated: 2024/02/20 13:51:13 by melmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lm -lX11 -lXext
MLXLIB = mlx/libmlx_Linux.a 

SRC = main.c \
ft_strcmp.c \
ft_error.c \
ft_memerror.c \
ft_atod.c \
ft_fractal_render.c \
ft_scale.c \
ft_do_maths.c \
ft_color_pxl.c \
ft_mouse_handler.c \
ft_close_handler.c \
ft_key_handler.c \
ft_init.c \

OBJ = $(SRC:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) $(MLXLIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) $(MLXLIB)

$(MLXLIB):
	make -C mlx

clean:
	rm -f $(OBJ)
	make -C mlx clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

