/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:26 by melmarti          #+#    #+#             */
/*   Updated: 2024/03/28 12:51:38 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_error(void)
{
	write(2, "Invalid parameters\n\nAvailable fractals and right formats :\n\n", 61);
	write(2, "\"Mandelbrot\"\n", 14);
	write(2, "\"Julia\" real_nb complex_nb\n", 28);
	write(2, "\"Burning bird\"\n", 16);
	write(2, "\"Burning bird julia\" real_nb complex_nb\n", 41);
	return (0);
}
