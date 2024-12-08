/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:53:13 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/08 18:14:16 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// [[0..799]] -> [-2..+2] linear interpolation function

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

//sum complex
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;
	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;

	return (result);
}

//square complex
// real = (x^2 - y^2)
// i = 2*x*y
t_complex square_complex(t_complex z)
{
	t_complex	result;
	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}