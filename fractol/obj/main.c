/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:53:16 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/13 18:31:41 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//  The main function of the program. It parses command-line arguments
// to determine which fractal to render and initializes the fractal program. 
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)
				|| !ft_strncmp(argv[1], "burning_ship", 12)
				|| !ft_strncmp(argv[1], "julia", 5)
				|| !ft_strncmp(argv[1], "newton", 6))))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Please enter:\n\t./fractol mandelbrot\n", 2);
		ft_putstr_fd("\t./fractol julia\n", 2);
		ft_putstr_fd("\t./fractol burning_ship\n", 2);
		ft_putstr_fd("\t./fractol newton\n", 2);
		exit(EXIT_FAILURE);
	}
}
