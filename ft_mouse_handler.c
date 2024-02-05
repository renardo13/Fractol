/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:49 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/02 16:51:12 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractal->zoom *= 1.05;
	else if (button == Button4)
		fractal->zoom *= 0.95;
	ft_fractal_render(fractal);
	return (0);
}
