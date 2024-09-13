/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:05:39 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 16:05:46 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
function sends a single character to a specified file descriptor 
using the write function.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
