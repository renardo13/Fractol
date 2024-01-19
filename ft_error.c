#include "fractol.h"

int	ft_error(void)
{
	write ( 2, "Please enter valid parameters <NAME> <COMPLEX NB>\n", 50);
	return (0);
}
