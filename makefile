CC = cc

CFLAGS = -Wall -Wextra -Werror -lm -lX11 -lXext /home/melmarti/42_projects/fractol/fractol/mlx/libmlx_Linux.a

SRC = 	main.c \
		ft_strcmp.c \
		ft_error.c \
		ft_memerror.c \
		ft_atod.c \
		ft_init.c \
		ft_fractal_render.c \
		ft_scale.c \
		ft_do_maths.c \
		ft_color_pxl.c \
		ft_key_handler.c \

ARRC = ar rc

NAME = fractol.a

EXECUTABLE = fractol

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(ARRC) $(EXECUTABLE) $(OBJ)

all: $(EXECUTABLE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean $(EXECUTABLE)

.PHONY: all clean fclean re

