/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:33:26 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/11 16:11:43 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_transform(t_complex *z, t_complex *c)
{
	*z = complex_add(complex_square(*z), *c);
}

void	handle_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = 0;
	z.y = 0;
	c.x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal->x = x;
	fractal->y = y;
	calculate_fractal(z, c, fractal, mandelbrot_transform);
}
