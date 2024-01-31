#include "fractol.h"

int	main(int ac, char **av)
{
	if (!(ac == 2 && ft_strcmp("Mandelbrot", av[1])) || !(ac == 4 && ft_strcmp("Julia", av[1])))
	{
    t_fractal fractal;

	fractal.name = av[1];
	ft_fractal_init(&fractal);
	ft_fractal_data(&fractal, av[2], av[3]);
	ft_fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	}
	else 
		ft_error();
	
	return (0);
}
