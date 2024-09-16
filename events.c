/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:04:42 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/16 11:47:54 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		ft_close_program(data);
		exit(1);
	}
	else if (keycode == 106)
	{
		ft_set_random_julia(&data->c.re, &data->c.im);
		ft_render_fractal(data);
	}
	return (0);
}

void	ft_zoom(t_data *data, int zoom_in, int mouse_x, int mouse_y)
{
	double	zoom_factor;
	double	re_factor;
	double	im_factor;
	double	mouse_re;
	double	mouse_im;

	if (zoom_in)
		zoom_factor = 1.0 / 1.42;
	else
		zoom_factor = 1.42;
	data->width = data->xmax - data->xmin;
	data->height = data->ymax - data->ymin;
	mouse_re = data->xmin + (mouse_x / (double)WIDTH) * data->width;
	mouse_im = data->ymin + (mouse_y / (double)HEIGHT) * data->height;
	re_factor = mouse_re - data->xmin;
	im_factor = mouse_im - data->ymin;
	data->xmin = mouse_re - re_factor * zoom_factor;
	data->xmax = mouse_re + (data->width - re_factor) * zoom_factor;
	data->ymin = mouse_im - im_factor * zoom_factor;
	data->ymax = mouse_im + (data->height - im_factor) * zoom_factor;
	ft_render_fractal(data);
}

int	ft_mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_UP)
		ft_zoom(data, 1, x, y);
	else if (button == SCROLL_DOWN)
		ft_zoom(data, 0, x, y);
	ft_render_fractal(data);
	return (0);
}

int	ft_close_window(t_data *data)
{
	ft_close_program(data);
	return (0);
}

void	ft_close_program(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	exit(0);
}
