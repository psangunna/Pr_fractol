/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:47:30 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 15:47:51 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*It finds the first ocurrence of c in the initial n bytes of the
* object pointed to by 'ptr'.
*/
void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (0);
}
