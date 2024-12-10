/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:53:16 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/10 16:23:17 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal fractal;

    if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10) || 
                       !ft_strncmp(argv[1], "burning_ship", 12) || 
                       !ft_strncmp(argv[1], "interesting", 11))) ||
        (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        fractal.name = argv[1];
        if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
        {
            fractal.julia_x = ft_atodbl(argv[2]);
            fractal.julia_y = ft_atodbl(argv[3]);
        }
        else
        {
            // Default values if not provided
            fractal.julia_x = -0.7;
            fractal.julia_y = 0.27015;
        }
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}


 