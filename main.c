#include "fractol.h"

int	main(int ac, char **av)
{
	if ((ac == 2 && ft_strcmp("Mandelbrot", av[1])) || (ac == 4 && ft_strcmp("Julia", av[1])))
	{
	// t_fractal fractal;
	// // void *mlx;
	// // void *mlx_win;

	// ft_fractal_init(&fractal);
	// ft_fractal_render(&fractal);
	// ft_mlx_loop(fractal.mlx_connexion);
	}
	else 
		ft_error();
	
	return (0);
}
