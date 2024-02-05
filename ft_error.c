/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:26 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/02 14:50:24 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_error(void)
{
	write(2, "Please enter valid parameters <Julia> <REAL> <COMPLEX NB>\n", 59);
	write(2, "OR <Mandelbrot>", 16);
	return (0);
}
