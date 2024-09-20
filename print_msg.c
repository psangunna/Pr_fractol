/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:20:10 by psangunna         #+#    #+#             */
/*   Updated: 2024/09/20 12:20:17 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putendl_fd("Usage: ./fractol <fractal>", 1);
	ft_putendl_fd("Available fractals: mandelbrot | julia rel_part img_part",
		1);
	ft_putstr_fd("**If you not specify any part for 'julia', it will be ",
		1);
	ft_putendl_fd("taken as default:-0.755 (rel_part) 0.05 (img_part)",
		1);
}

void	ft_print_available_commands(void)
{
	ft_putendl_fd("Commands available:", 1);
	ft_putendl_fd("\tUse mouse wheel to zoom in and out.", 1);
	ft_putendl_fd("\tUse J: changes julia fractal set.", 1);
}
