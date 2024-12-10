/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:47:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/10 18:32:36 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

#define ERROR_MESSAGE "Please enter \n\t\".fractol mandelbrot\" for \n\t\"./fractol .julia <value_1> <value_2>\"\n"

// we use a square to keep the rendering math simple
#define WIDTH	1000
#define HEIGHT	1000

//COLORS

#define COLOR_BLACK   0x000000
#define COLOR_RED     0xFF0000
#define COLOR_GREEN   0x00FF00
#define COLOR_YELLOW  0xFFFF00
#define COLOR_BLUE    0x0000FF
#define COLOR_MAGENTA 0xFF00FF
#define COLOR_CYAN    0x00FFFF
#define COLOR_WHITE   0xFFFFFF

// Psychedelic colors
#define COLOR_NEON_PINK        0xFF1493
#define COLOR_ELECTRIC_PURPLE  0xBF00FF
#define COLOR_ACID_GREEN       0xB0FF00
#define COLOR_PSYCHEDELIC_ORANGE 0xFF7F00
#define COLOR_ELECTRIC_BLUE    0x00FFFF
#define COLOR_HOT_PINK         0xFF69B4
#define COLOR_LIME_GREEN       0x32CD32
#define COLOR_DEEP_PINK        0xFF1493
#define COLOR_TURQUOISE        0x40E0D0
#define COLOR_VIVID_VIOLET     0x9F00FF
#define COLOR_NEON_YELLOW      0xFFFF00
#define COLOR_FLUORESCENT_GREEN 0x00FF00



// COMPLEX value
typedef	struct	s_complex
{
	//real
	double	x;
	//i
	double	y;
}				t_complex;


/*
* IMAGE
* This is basically a pixels buffer
* values from mlx_get_data_addr()
*/

typedef struct	s_img
{
	void		*img_ptr; //pointer to image struct
	char		*pixels_ptr; //point to the actual pixels
	int			bpp; //bits per puxel
	int			endian;
	int			line_len;
}				t_img;

/*
* FRACTAL ID
* ~ MLX stuff
* ~ Image
* ~ Hooks values
*/


typedef struct	s_fractal
{
	char		*name;
	//MLX
	void		*mlx_connection; //mlx_init()
	void		*mlx_window;	//mlx_new_window()
	//Image
	t_img		img;
	
	//Hooks member variables
	double		escape_value; //hypotenuse
	int			iterations_definition; // value tight with the image quality and rendering speed
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
	int			x;
    int			y;
	void		(*fractal_function)(int, int, struct s_fractal*);
	int			color_shift;
}				t_fractal;

// init
void		fractal_init(t_fractal *fractal);
int			color_cycle(t_fractal *fractal);

//render
void		fractal_render(t_fractal *fractal);
int 		get_color(int iterations, t_fractal *fractal);


// math
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex 	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex z);
t_complex 	complex_i_pow(t_complex z);

// hooks events
int			key_handler(int keysym, t_fractal *fractal);

//cleanup
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
// int			julia_track(int x, int y, t_fractal *fractal);



#endif