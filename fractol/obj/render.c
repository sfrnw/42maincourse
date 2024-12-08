/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:47:45 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/08 19:40:08 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// put a pixel in my image buffer
static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y* img->line_len) + (x * (img->bpp/8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
static void handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	// 1 iteration
	z.x = 0.0;
	z.y	= 0.0;

	// pixel coordinate x & y scaled to fit mandelbrot needs
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, 2, -2, 0, HEIGHT);

	//how many times you want to iterate z^2 +c
	while (i < fractal->iterations_definition)
	{
		//actual z^2 +c
		//z = z^2 +c
		z = sum_complex(square_complex(z),c); //todo
		//is the value escaped??
		// us hypotenuse > 2 i assume the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escaped_value)
		{
			color = map(i, COLOR_BLACK, COLOR_WHITE, 0, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color); //todo
			return ;
		}
		++i;
	}
	//we are in MANDELBROT given the iterations made
	my_pixel_put(x, y, &fractal->img, COLOR_ELECTRIC_PURPLE);
}

void fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}