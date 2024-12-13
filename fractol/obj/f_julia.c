/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:33:43 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/13 18:28:50 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//	This function calculates the Julia set fractal
//	for a given pixel coordinate. 
void	handle_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = (map(x, -2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	fractal->x = x;
	fractal->y = y;
	calculate_fractal(z, c, fractal, mandelbrot_transform);
}
