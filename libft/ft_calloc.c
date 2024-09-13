/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:51:28 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 15:53:34 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*It allocates a specified amount of memory and then initialized it to zero.
*The function return a void pointer to this memory location,
* which can then be cast to the desired type.
*/
void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	total_size;
	void	*ptr;

	total_size = nelem * elsize;
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
