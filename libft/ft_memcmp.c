/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:05:08 by pamela            #+#    #+#             */
/*   Updated: 2024/04/14 20:08:45 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
** Compare two memory areas byte by byte up to a specified length.
** Returns:
** 0 if both memory areas are equal.
** A positive value if the first differing byte in ptr1 is greater 
** than the corresponding byte in ptr2.
** A negative value if the first differing byte in ptr1 is less than t
**he corresponding byte in ptr2.
*
*/
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)ptr1;
	p2 = (const unsigned char *)ptr2;
	while (n > 0)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
		n--;
	}
	return (0);
}
