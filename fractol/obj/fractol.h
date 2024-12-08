/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:47:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/08 19:27:28 by asafrono         ###   ########.fr       */
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

#define ERROR_MESSAGE "Please enter \n\t\".fractol mandelbrot\" for \n\t\"./fractol .julia <value_1> <value_2>\"\n"

// we use a square to keep the rendering math simple
#define WIDTH	800
#define HEIGHT	800

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

// // Basic colors
// #define COLOR_BLACK "\x1b[30m"
// #define COLOR_RED "\x1b[31m"
// #define COLOR_GREEN "\x1b[32m"
// #define COLOR_YELLOW "\x1b[33m"
// #define COLOR_BLUE "\x1b[34m"
// #define COLOR_MAGENTA "\x1b[35m"
// #define COLOR_CYAN "\x1b[36m"
// #define COLOR_WHITE "\x1b[37m"

// // Bright colors
// #define COLOR_BRIGHT_BLACK "\x1b[90m"
// #define COLOR_BRIGHT_RED "\x1b[91m"
// #define COLOR_BRIGHT_GREEN "\x1b[92m"
// #define COLOR_BRIGHT_YELLOW "\x1b[93m"
// #define COLOR_BRIGHT_BLUE "\x1b[94m"
// #define COLOR_BRIGHT_MAGENTA "\x1b[95m"
// #define COLOR_BRIGHT_CYAN "\x1b[96m"
// #define COLOR_BRIGHT_WHITE "\x1b[97m"

// // Psychedelic and vibrant colors
// #define COLOR_NEON_PINK "\x1b[38;2;255;20;147m"
// #define COLOR_ELECTRIC_PURPLE "\x1b[38;2;191;0;255m"
// #define COLOR_ACID_GREEN "\x1b[38;2;176;255;0m"
// #define COLOR_PSYCHEDELIC_ORANGE "\x1b[38;2;255;127;0m"
// #define COLOR_ELECTRIC_BLUE "\x1b[38;2;0;255;255m"
// #define COLOR_NEON_YELLOW "\x1b[38;2;255;255;0m"
// #define COLOR_FLUORESCENT_GREEN "\x1b[38;2;0;255;0m"
// #define COLOR_HOT_PINK "\x1b[38;2;255;105;180m"

// // Reset color
// #define COLOR_RESET "\x1b[0m"


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

typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //point to the actual pixels
	int		bpp; //bits per puxel
	int		endian;
	int		line_len;
}			t_img;

/*
* FRACTAL ID
* ~ MLX stuff
* ~ Image
* ~ Hooks values
*/


typedef struct	s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection; //mlx_init()
	void	*mlx_window;	//mlx_new_window()
	//Image
	t_img	img;
	
	//Hooks member variables
	double	escaped_value; //hypotenuse
	int		iterations_definition; // value tight with the image quality and rendering speed

}				t_fractal;

// init
void		fractal_init(t_fractal *fractal);

//render
void fractal_render(t_fractal *fractal);

// math
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif