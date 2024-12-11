/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:47:45 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/11 16:12:16 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

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
			color = get_color(i, fractal);
			my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(fractal->x, fractal->y, &fractal->img, COLOR_BLACK);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
		handle_julia(x, y, fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		handle_mandelbrot(x, y, fractal);
	else if (!ft_strncmp(fractal->name, "burning_ship", 10))
		handle_burning_ship(x, y, fractal);
	else if (!ft_strncmp(fractal->name, "interesting", 11))
		handle_interesting_fractal(x, y, fractal);
}

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

int	get_color(int iterations, t_fractal *fractal)
{
	double	t;
	int		shift;
	int		r;
	int		g;
	int		b;

	t = (double)iterations / fractal->iterations_definition;
	shift = fractal->color_shift;
	r = (int)((sin(t * 5 + shift * 0.1) * 0.5 + 0.5) * 255);
	g = (int)((sin(t * 5 + shift * 0.1 + 2.094) * 0.5 + 0.5) * 255);
	b = (int)((sin(t * 5 + shift * 0.1 + 4.188) * 0.5 + 0.5) * 255);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return ((r << 16) | (g << 8) | b);
}
