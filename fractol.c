/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:50:17 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/16 11:50:25 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractals");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->xmin = -2.0;
	data->xmax = 2.0;
	data->ymin = -2.0;
	data->ymax = 2.0;
	data->max_iter = 100;
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->width = 0.0;
	data->height = 0.0;
	return (1);
}

static int	ft_handle_input(t_data *data, int argc, char **argv)
{
	if (argc < 2 || !ft_valid_fractal(argv[1]))
	{
		ft_print_usage();
		return (0);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		data->fractal_type = MANDELBROT;
		return (1);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		data->fractal_type = JULIA;
		ft_set_julia_params(data, argc, argv);
		return (1);
	}
	else
	{
		ft_print_usage();
		return (0);
	}
	return (0);
}

void	ft_render_fractal(t_data *data)
{
	if (data && data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data)
	{
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		if (!data->img)
			return ;
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		ft_update_view(data);
		if (data->fractal_type == MANDELBROT)
		{
			ft_draw_mandelbrot(data);
		}
		else if (data->fractal_type == JULIA)
		{
			ft_draw_julia(data);
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
}

static void	ft_setup_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->win, 17, 1L << 17, ft_close_window, data);
	mlx_mouse_hook(data->win, ft_mouse_hook, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_handle_input(&data, argc, argv))
		return (1);
	if (!ft_init_data(&data))
		return (1);
	ft_render_fractal(&data);
	ft_print_available_commands();
	ft_setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
