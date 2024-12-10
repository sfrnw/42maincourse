/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:21 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/10 14:46:09 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}
//keypress
int	key_handler(int keysym, t_fractal *fractal)
{
	// (void)fractal;
	// printf("%d\n", keysym);

	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_z)
		fractal->iterations_definition += 10;
	else if (keysym == XK_x)
		fractal->iterations_definition -= 10;
	
	// refresh image
	fractal_render(fractal);
	
	return(0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	//zoom in
	if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	//zoom out
	else if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}

	// printf("%d\n", button);
	// refresh image
	fractal_render(fractal);
	
	return(0);	
}

// track the mouse to change kilia dinamically
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + 0.01 * fractal->shift_x;
		fractal->julia_y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + 0.01 * fractal->shift_y;
		fractal_render (fractal);
	}
	return (0);
}