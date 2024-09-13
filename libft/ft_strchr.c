/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:07:35 by pamela            #+#    #+#             */
/*   Updated: 2024/04/14 20:07:39 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
It finds the first occurrence of a character in a string
*/
char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char)c)
	{
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return (0);
}
