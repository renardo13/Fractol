#include "fractol.h"

int	ft_error(void)
{
	write ( 2, "Please enter valid parameters <Julia> <REAL> <COMPLEX NB>\n", 59);
	write (2, "OR <Mandelbrot>", 16);
	return (0);
}
