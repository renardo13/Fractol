/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:47 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/02 16:41:54 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strcmp("Mandelbrot", av[1])) || (ac == 4
			&& !ft_strcmp("Julia", av[1])))
	{
		fractal.name = av[1];
		ft_fractal_init(&fractal);
		ft_events_init(&fractal);
		ft_fractal_data(&fractal, av[2], av[3]);
		ft_fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		ft_error();
	return (0);
}
