/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:47:45 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/10 16:34:19 by asafrono         ###   ########.fr       */
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

static void calculate_fractal(t_complex z, t_complex c, t_fractal *fractal, 
                              void (*transform)(t_complex*, t_complex*))
{
    int i = 0;
    int color;

    while (i < fractal->iterations_definition)
    {
        transform(&z, &c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->escaped_value_2)
        {
            color = map(i, COLOR_BLACK, COLOR_WHITE, 0, fractal->iterations_definition);
            my_pixel_put(fractal->x, fractal->y, &fractal->img, color);
            return;
        }
        ++i;
    }
    my_pixel_put(fractal->x, fractal->y, &fractal->img, COLOR_BLACK);
}

// Mandelbrot
static void mandelbrot_transform(t_complex *z, t_complex *c)
{
    *z = complex_add(complex_square(*z), *c);
}

static void handle_mandelbrot(int x, int y, t_fractal *fractal)
{
    t_complex z = {0, 0};
    t_complex c;

    c.x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
    
    fractal->x = x;
    fractal->y = y;
    calculate_fractal(z, c, fractal, mandelbrot_transform);
}
//Julia

static void handle_julia(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;

    z.x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
    c.x = fractal->julia_x;
    c.y = fractal->julia_y;
    
    fractal->x = x;
    fractal->y = y;
    calculate_fractal(z, c, fractal, mandelbrot_transform);
}

// Burning Ship transform function
static void burning_ship_transform(t_complex *z, t_complex *c)
{
    z->x = fabs(z->x);
    z->y = fabs(z->y);
    *z = complex_add(complex_square(*z), *c);
}

static void handle_burning_ship(int x, int y, t_fractal *fractal)
{
    t_complex z = {0, 0};
    t_complex c;

    c.x = (map(x, -2, 1, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (map(y, -2, 1, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
    
    fractal->x = x;
    fractal->y = y;
    calculate_fractal(z, c, fractal, burning_ship_transform);
}
//interesting
static void interesting_fractal_transform(t_complex *z, t_complex *c)
{
    *z = complex_add(complex_i_pow(*z), *c);
}

static void handle_interesting_fractal(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;

    z.x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (map(y, -2, 2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
    c.x = -0.4;  // You might want to rename these to more generic names
    c.y = -0.01;  // like constant_x and constant_y
    
    fractal->x = x;
    fractal->y = y;
    calculate_fractal(z, c, fractal, interesting_fractal_transform);
}


static void handle_pixel(int x, int y, t_fractal *fractal)
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

void fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}