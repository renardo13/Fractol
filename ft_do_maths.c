/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:22 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/05 19:20:25 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_abs(int nb)
{
	if (nb < 0)
		nb *= (-1);
	return (nb);
}
t_complex ft_remarkable(t_complex z)
{
	t_complex result;
	(z.x * z.x) + (2 * z.y * z.x) + (z.y * z.y);
	return (result);
}


t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
