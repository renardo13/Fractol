/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_pxl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:19 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/05 19:19:34 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_put_color(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	ft_which_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp("Julia", fractal->name))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	ft_color_pxl(double x, double y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (ft_scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (ft_scale(y, -2, 2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	ft_which_fractal(&z, &c, fractal);
	i = 0;
	while (i < fractal->iter)
	{
		if (!ft_strcmp("Burning_bird", fractal->name))
			z = ft_remarkable(z);
		else 
			z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_scale(i, 0, 1000, 40);
			ft_put_color(x, y, &fractal->img, color);
			return ;
		}
		ft_put_color(x, y, &fractal->img, 0);
		i++;
	}
}
