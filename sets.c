/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:26:07 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/13 18:42:14 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Función para obtener el número de iteraciones en el conjunto de Mandelbrot
int	ft_mandelbrot(t_complex c, int max_iter)
{
	int			n;
	double	temp_re;

	t_complex z;
	z.re = 0;
	z.im = 0;
	n = 0;

	while ((z.re * z.re + z.im * z.im <= 4) && (n < max_iter))
	{
		temp_re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp_re;
		n++;
	}
	return (n);
}

void	ft_draw_mandelbrot(t_data *data) //otros
{
	int	x;
	int	y;
	int	n;
	int	color;

	for (x = 0; x < WIDTH; x++)
	{
		for (y = 0; y < HEIGHT; y++)
		{
			t_complex c;
			c.re = data->xmin + x * (data->xmax - data->xmin) / WIDTH;
			c.im = data->ymin + y * (data->ymax - data->ymin) / HEIGHT;
			n = ft_mandelbrot(c, data->max_iter);
			color = ft_color_map(n, data->max_iter);
			ft_mlx_pixel_put(data, x, y, color);
		}
	}
}

void	ft_set_random_julia(double *cx, double *cy)
{
	*cx = ft_generate_random_c();
	*cy = ft_generate_random_c();
}

int	ft_julia(t_complex z, t_complex c, int max_iter)
{
	int		n;
	double	temp_re;

	n = 0;
	while ((z.re * z.re + z.im * z.im <= 4) && (n < max_iter))
	{
		temp_re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp_re;
		n++;
	}
	return (n);
}

void	ft_draw_julia(t_data *data)
{
	int	x;
	int	y;
	int	n;
	int	color;

	for (x = 0; x < WIDTH; x++)
	{
		for (y = 0; y < HEIGHT; y++)
		{
			t_complex z;
			z.re = data->xmin + x * (data->xmax - data->xmin) / WIDTH;
			z.im = data->ymin + y * (data->ymax - data->ymin) / HEIGHT;
			n = ft_julia(z, data->c, data->max_iter);
			color = ft_color_map(n, data->max_iter);
			ft_mlx_pixel_put(data, x, y, color);
		}
	}
}


