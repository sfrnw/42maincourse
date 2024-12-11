/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:53:13 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/11 13:47:26 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// [[0..799]] -> [-2..+2] linear interpolation function

double	map(double unscaled_num, double new_min, double new_max,
		double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
}

//square complex
// real = (x^2 - y^2)
// i = 2*x*y
t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

// Complex exponentiation (i^z)
t_complex	complex_i_pow(t_complex z)
{
	t_complex	result;
	double		e_ny;

	e_ny = exp(-z.y);
	result.x = e_ny * sin(z.x);
	result.y = e_ny * cos(z.x);
	return (result);
}

// Complex addition
t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}
