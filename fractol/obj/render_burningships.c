/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_burningships.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:34:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/11 13:50:18 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	burning_ship_transform(t_complex *z, t_complex *c)
{
	z->x = fabs(z->x);
	z->y = fabs(z->y);
	*z = complex_add(complex_square(*z), *c);
}

void	handle_burning_ship(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = 0;
	z.y = 0;
	c.x = (map(x, -2, 1, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (map(y, -2, 1, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal->x = x;
	fractal->y = y;
	calculate_fractal(z, c, fractal, burning_ship_transform);
}
