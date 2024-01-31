#include "fractol.h"

static void ft_put_color(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void ft_which_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (!ft_strcmp("Mandelbrot", fractal->name))
    {
        c->x = z->x;
        c->y = z->y;
    }
    else
    {
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
}

void ft_color_pxl(double x, double y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = (ft_scale(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (ft_scale(y, -2, 2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

    ft_which_fractal(&z, &c, fractal);
    i = 0;
    while (i < fractal->iter)
    {
        z = ft_sum_complex(ft_square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > 4)
        {
            color = ft_scale(i, 0, 255, 0, 40);
            ft_put_color(x, y, &fractal->img, color);
            return;
        }
        ft_put_color(x, y, &fractal->img, 0); 
        i++;
    }
}
