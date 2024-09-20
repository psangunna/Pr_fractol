/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:50:54 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/16 11:54:33 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_valid_fractal(char *fractal)
{
	return (ft_strncmp(fractal, "mandelbrot", 10) == 0
		|| ft_strncmp(fractal, "julia", 5) == 0);
}

void	ft_update_view(t_data *data)
{
	data->width = data->xmax - data->xmin;
	data->height = data->ymax - data->ymin;
	data->xmin += data->offset_x * data->width;
	data->xmax = data->xmin + data->width / data->zoom;
	data->ymin += data->offset_y * data->height;
	data->ymax = data->ymin + data->height / data->zoom;
}

static const char	*ft_del_whitespace_and_sign(const char *str, int *sign)
{
	*sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

double	ft_atof(const char *str)
{
	double	result;
	double	divisor;
	int		sign;

	result = 0.0;
	divisor = 10.0;
	str = ft_del_whitespace_and_sign(str, &sign);
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
