#include "fractol.h"

void ft_fractal_render(t_fractal *fractal)
{
	double x;
	double y;

	y = 0;
	while (y++ < WIDTH)
	{
		x = 0;
		while (x++ < HEIGHT)
		{
			ft_color_pxl(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);	
}
