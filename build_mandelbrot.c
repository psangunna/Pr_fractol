/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:59:53 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/16 12:07:47 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	double		temp_re;
	int			n;

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

void	ft_draw_mandelbrot(t_data *data)
{
	t_complex	c;
	int			color;
	int			x;
	int			y;
	int			n;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.re = data->xmin + x * (data->xmax - data->xmin) / WIDTH;
			c.im = data->ymin + y * (data->ymax - data->ymin) / HEIGHT;
			n = ft_mandelbrot(c, data->max_iter);
			color = ft_color_map(n, data->max_iter);
			ft_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}
