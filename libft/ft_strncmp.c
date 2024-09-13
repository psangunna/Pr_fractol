/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:03:31 by pamela            #+#    #+#             */
/*   Updated: 2024/04/14 20:03:36 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
Compare two strings up to a specified length
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && (*str1 || *str2))
	{
		if (*str1 != *str2)
		{
			return ((unsigned char)*str1 - (unsigned char)*str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
