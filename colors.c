/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:58:54 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/13 18:04:18 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Función para colocar un píxel en la imagen
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Función para mapear el valor de iteraciones a un color
int	ft_color_map(int n, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)n / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}
