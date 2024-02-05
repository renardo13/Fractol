# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 14:49:52 by melmarti          #+#    #+#              #
#    Updated: 2024/02/02 15:40:35 by melmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lm -lX11 -lXext
MLXLIB = /home/melmarti/42_projects/fractol/mlx/libmlx_Linux.a

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

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) $(MLXLIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

