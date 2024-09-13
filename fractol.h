/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:14:34 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/13 18:24:33 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MANDELBROT 1
# define JULIA 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr; //pointer_to_image
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractal_type;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	int		color;//
	double	offset_x;//
	double	offset_y;//
	double	zoom;//
	int		max_iter;
	t_complex		c;
}	t_data;

/*
typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;
*/
int		ft_init_data(t_data *data);
int		ft_handle_input(t_data *data, int argc, char **argv);
void	ft_render_fractal(t_data *data);
void	ft_setup_hooks(t_data *data);
void	ft_draw_mandelbrot(t_data *data);
void	ft_draw_julia(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_close_window(t_data *data);
void	ft_close_program(t_data *data);
void	ft_print_usage(void);
int		ft_valid_fractal(char *fractal);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_color_map(int n, int max_iter);
void	ft_update_view(t_data *data);
double	ft_generate_random_c(void);
void	ft_set_random_julia(double *cx, double *cy);
double	ft_atof(const char *str);
int		ft_mouse_hook(int button, int x, int y, t_data *data);

#endif
