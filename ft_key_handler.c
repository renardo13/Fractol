/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:34 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/29 12:19:37 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// we use keysym to be sure that the right code is
// used because the keycode can be different according to keyboards

void	ft_julia_set(t_fractal *fractal)
{
	static int	i;
	double		real[7];
	double		im[7];

	real[0] = 0.25;
	im[0] = 0.5;
	real[1] = -0.8;
	im[1] = 0.156;
	real[2] = 0.285;
	im[2] = 0.01;
	real[3] = -0.038088;
	im[3] = 0.9754633;
	real[4] = 0.35;
	im[4] = 0.35;
	im[5] = 0.4;
	real[5] = 0.4;
	im[6] = -0.7269;
	real[6] = 0.1889;
	fractal->real = real[i];
	fractal->im = im[i];
	if (i == 6)
		i = 0;
	i++;
}

int	ft_key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_minus)
		fractal->iter -= 10;
	else if (keysym == XK_equal)
		fractal->iter += 10;
	else if (keysym == 32)
		fractal->colors += 20;
	else if (keysym == XK_j && (!ft_strcmp("Julia", fractal->name)
			|| !ft_strcmp("Burning bird julia", fractal->name)))
		ft_julia_set(fractal);
	ft_fractal_render(fractal);
	return (0);
}
