/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:10:19 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/16 12:19:03 by psangunna        ###   ########.fr       */
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
	t_complex	c;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fractal_type;
	int			max_iter;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		offset_x;
	double		offset_y;
	double		zoom;
	double		width;
	double		height;
}	t_data;

void	ft_render_fractal(t_data *data);
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
void	ft_set_random_julia(double *cx, double *cy);
double	ft_atof(const char *str);
int		ft_mouse_hook(int button, int x, int y, t_data *data);
void	ft_set_julia_params(t_data *data, int argc, char **argv);

#endif
