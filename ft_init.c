/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:31 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/05 18:46:33 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, ft_key_handler,
		fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask,
		ft_mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		ft_close_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask,
		ft_track_mouse, fractal);
}

void	ft_fractal_data(t_fractal *fractal, char *real, char *im)
{
	if (!ft_strcmp("Julia", fractal->name))
	{
		fractal->julia_x = ft_atod(real);
		fractal->julia_y = ft_atod(im);
	}
	fractal->iter = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	ft_fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		ft_memerror();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		ft_memerror();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		ft_memerror();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}

/* int	ft_track_mouse(int x, int y, t_fractal *fractal)
{

	(void)x;
	(void)y;
	if (!ft_strcmp(fractal->name, "Julia"))
	{
		fractal->julia_x = (ft_scale(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (ft_scale(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		ft_fractal_render(fractal);
	}
	return (0);
} */

