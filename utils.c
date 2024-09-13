/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:46:43 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/13 18:44:02 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_valid_fractal(char *fractal)
{
	return (ft_strncmp(fractal, "mandelbrot", 10) == 0 || ft_strncmp(fractal, "julia", 5) == 0);
}

void	ft_print_usage(void)
{
	ft_putendl_fd("Usage: ./fractol <fractal>", 1);
	ft_putendl_fd("Available fractals: mandelbrot | julia real_part imag_part", 1);
}

void	ft_update_view(t_data *data)
{
	double width = data->xmax - data->xmin;
	double height = data->ymax - data->ymin;
	// Ajusta el rango basado en el nivel de zoom
	data->xmin += data->offset_x * width;
	data->xmax = data->xmin + width / data->zoom;
	data->ymin += data->offset_y * height;
	data->ymax = data->ymin + height / data->zoom;
}

double	ft_generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

double	ft_atof(const char *str)
{
	double	result;
	double	divisor;
	int		sign = 1;

	result = 0.0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	result = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		divisor = 10.0;
		while (ft_isdigit(*str))
		{
			result += (*str - '0') / divisor;
			divisor *= 10.0;
			str++;
		}
	}
	result *= sign;
	return (result);
}
