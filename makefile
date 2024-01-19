CC = cc

CFLAGS = -Wall -Wextra -Werror -lm mlx/libmlx_Linux.a -lXext -lX11

SRC = 	main.c \
		ft_strcmp.c \
		ft_error.c \
		ft_memerror.c \
		ft_atod.c \
		ft_fractal_init.c \

OBJ = $(SRC:.c=.o) 

NAME = fractol

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)

re: fclean $(NAME) $(NAME)

.PHONY: all clean fclean re
