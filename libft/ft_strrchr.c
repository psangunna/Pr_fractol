/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:04:41 by pamela            #+#    #+#             */
/*   Updated: 2024/04/14 20:04:45 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
Find the last occurrence of a character in a string (searching in reverse)
*/
char	*ft_strrchr(const char *str, int c)
{
	const char	*last_value;

	last_value = NULL;
	while (*str)
	{
		if (*str == (char)c)
		{
			last_value = str;
		}
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return ((char *)last_value);
}
