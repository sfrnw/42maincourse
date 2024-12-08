/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:37:58 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/08 13:47:35 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_complex
{
	//	x;
	double	real;
	// y
	double	i;
}				t_complex;

int main()
{
	t_complex	z;
	//point
	t_complex	c;
	double		tmp_real;
	int			k;
	
	z.real = 0;
	z.i	= 0;

	c.real =5;
	c.i = 2;

	k = -1;
	while (++k < 42)
	{
		//general formula
		//z = z^2 + c;
		tmp_real = (z.real * z.real) - (z.i*z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;

		//adding the c value
		z.real += c.real;
		z.i += c.i;

		printf("iteration n -> %d real %f imaginary%f\n", k, z.real, z.i);
	}
	
}