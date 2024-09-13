/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:40:53 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/13 17:46:16 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractals");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->xmin = -2.0;
	data->xmax = 2.0;
	data->ymin = -2.0;
	data->ymax = 2.0;
	data->max_iter = 100;
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	return (1);
}

int	ft_handle_input(t_data *data, int argc, char **argv)
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
	else if (ft_strncmp(argv[1], "julia", 5) == 0 )
	{
		data->fractal_type = JULIA;
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
	// Imprimir el valor actual de data->img
	printf("Current data->img: %p\n", (void *)data->img);
	// Destruir la imagen anterior si existe
	if (data && data->img)
	{
		printf("Destroying image at: %p\n", (void *)data->img);
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL; // Asegúrate de que el puntero a imagen sea NULL después de destruir
	}
	// Crear una nueva imagen con las dimensiones de la ventana
	if (data)
	{
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		printf("New data->img created at: %p\n", (void *)data->img);
		if (!data->img)
			return;
		// Obtener el puntero a los píxeles de la imagen
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		// Actualiza el rango del plano complejo
		ft_update_view(data);
		// Dibuja el fractal
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

void	ft_setup_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, ft_key_press, data); // ESC key event
	mlx_hook(data->win, 17, 1L << 17, ft_close_window, data); // Close button event
	mlx_mouse_hook(data->win, ft_mouse_hook, data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	// Inicializar estructura de datos y MiniLibX
	if (!ft_init_data(&data))
		return (1);
	// Configurar el tipo de fractal según los argumentos CLI
	//Si ft_handle_input devuelve 0, se ejecuta return 1
	if (!ft_handle_input(&data, argc, argv))
	{
		ft_close_program(&data);
		return (1);
	}
	// Dibujar el fractal seleccionado
	ft_render_fractal(&data);
	// Configurar los eventos (teclas, ratón, cierre de ventana)
	ft_setup_hooks(&data);// Aquí registras los eventos
	// Iniciar el loop de eventos de MiniLibX
	mlx_loop(data.mlx);
	return (0);
}
