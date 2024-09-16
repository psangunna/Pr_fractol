/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:55:12 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/16 11:58:58 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_julia_params(t_data *data, int argc, char **argv)
{
	if (argc == 4)
	{
		data->c.re = ft_atof(argv[2]);
		data->c.im = ft_atof(argv[3]);
	}
	else
	{
		data->c.re = -0.745429;
		data->c.im = 0.05;
	}
}

static double	ft_generate_random_j(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	ft_set_random_julia(double *cx, double *cy)
{
	*cx = ft_generate_random_j();
	*cy = ft_generate_random_j();
}

static int	ft_julia(t_complex z, t_complex c, int max_iter)
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
	t_complex	z;
	int			x;
	int			y;
	int			n;
	int			color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z.re = data->xmin + x * (data->xmax - data->xmin) / WIDTH;
			z.im = data->ymin + y * (data->ymax - data->ymin) / HEIGHT;
			n = ft_julia(z, data->c, data->max_iter);
			color = ft_color_map(n, data->max_iter);
			ft_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}
