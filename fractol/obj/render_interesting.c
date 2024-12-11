/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_interesting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:46:56 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/11 16:22:50 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	interesting_fractal_transform(t_complex *z, t_complex *c)
{
	*z = complex_add(complex_i_pow(*z), *c);
}

void	handle_interesting_fractal(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	fractal->escape_value = 10000;
	z.x = (map(x, -5, 5, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, -5, 1, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.x = -0.4;
	c.y = -0.01;
	fractal->x = x;
	fractal->y = y;
	calculate_fractal(z, c, fractal, interesting_fractal_transform);
}

// need to change rendering because ecape formula should be different