#include "fractol.h"

void ft_memerror(void)
{
	write (2, "Malloc Error\n", 13);
	exit(1);
}
