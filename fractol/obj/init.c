/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:58:25 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/14 13:21:14 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//  This function handles memory allocation errors by displaying
//	an error message and closing the program. 
static void	malloc_error(t_fractal *fractal)
{
	ft_putstr_fd("Error: Memory allocation failed\n", 2);
	close_handler(fractal);
}

// Julia
// {"Classic", -0.7, 0.27015};
// {"Dendrite", -0.8, 0.156};
// {"Spiral", 0.285, 0.01};
// {"Siegel Disk", -0.391, -0.587};
// {"Rabbit", -0.123, 0.745}; 

// This function initializes the fractal parameters with default values. 
static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 10;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color_shift = 0;
	if (!fractal->julia_x)
		fractal->julia_x = 0.285;
	if (!fractal->julia_y)
		fractal->julia_x = 0.01;
}

//	 This function sets up event handlers for keyboard and mouse input. 
static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask,
		mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
	mlx_loop_hook(fractal->mlx_connection, cycle, fractal);
}

//  This function initializes the fractal program by setting up the MLX library,
//	creating a window, and initializing the image buffer. 
void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error(fractal);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error(fractal);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
		malloc_error(fractal);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len,
			&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}

// This function is called repeatedly to create animation effects.
// It gradually shifts colors and updates Julia set parameters over time. 
int	cycle(t_fractal *fractal)
{
	static int	frame_count = 0;
	static int	direction = 1;

	frame_count++;
	if (frame_count >= 60)
	{
		fractal->color_shift = (fractal->color_shift + 1) % 360;
		fractal->julia_x += direction * 0.01;
		fractal->julia_y += direction * 0.01;
		if (fractal->julia_x >= 2.0 || fractal->julia_x <= -2.0
			|| fractal->julia_y >= 2.0 || fractal->julia_y <= -2.0)
		{
			direction *= -1;
		}
		fractal_render(fractal);
		frame_count = 0;
	}
	return (0);
}
