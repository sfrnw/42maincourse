/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:47:45 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/13 18:33:40 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//	This function sets the color of a specific pixel in the image buffer. 
void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

//	This function performs the iterative calculation
//	for a fractal at a given point. 
void	calculate_fractal(t_complex z, t_complex c, t_fractal *fractal,
			void (*transform)(t_complex*, t_complex*))
{
	int	i;
	int	color;

	i = 0;
	while (i < fractal->iterations_definition)
	{
		transform(&z, &c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = get_color(i, fractal->iterations_definition,
					fractal->color_shift, 0);
			my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(fractal->x, fractal->y, &fractal->img, COLOR_BLACK);
}

//  This function determines which fractal calculation
//	to use based on the selected fractal type. 
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
		handle_julia(x, y, fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		handle_mandelbrot(x, y, fractal);
	else if (!ft_strncmp(fractal->name, "burning_ship", 10))
		handle_burning_ship(x, y, fractal);
	else if (!ft_strncmp(fractal->name, "newton", 6))
		handle_newton(x, y, fractal);
}

//	This function renders the entire fractal by calculating the color
//	for each pixel and displaying the resulting image.
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
