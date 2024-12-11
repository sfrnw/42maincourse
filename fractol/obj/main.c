/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:53:16 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/11 16:17:03 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// {"Classic", -0.7, 0.27015};
// {"Dendrite", -0.8, 0.156};
// {"Spiral", 0.285, 0.01};
// {"Siegel Disk", -0.391, -0.587};
// {"Rabbit", -0.123, 0.745};    

static void set_julia_params(t_fractal *fractal)
{
	fractal->julia_x = -0.7;
    fractal->julia_y = 0.27015;
}

int main(int argc, char **argv)
{
    t_fractal fractal;

    if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)
                || !ft_strncmp(argv[1], "burning_ship", 12)
                || !ft_strncmp(argv[1], "interesting", 11)
                || !ft_strncmp(argv[1], "julia", 5))))
    {
        fractal.name = argv[1];
        if (!ft_strncmp(argv[1], "julia", 5))
            set_julia_params(&fractal);
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        ft_putstr_fd("Please enter:\n\t./fractol mandelbrot\n", STDERR_FILENO);
        ft_putstr_fd("\t./fractol julia\n", STDERR_FILENO);
        ft_putstr_fd("\t./fractol burning_ship\n", STDERR_FILENO);
        ft_putstr_fd("\t./fractol interesting\n", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}
