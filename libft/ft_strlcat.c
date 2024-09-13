/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:34:33 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/13 19:56:14 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 *It concatenates two strings with a specified maximun 'size',
 *ensuring that the destination buffer does not overflow.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	i;
	size_t	len_total;

	if (!dest && !size)
		return (ft_strlen(src));
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	len_dest = ft_strlen(dest);
	len_total = len_dest + ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && len_dest + 1 < size)
	{
		dest[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dest[len_dest] = '\0';
	return (len_total);
}
