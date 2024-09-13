/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:53:53 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/13 20:08:46 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
*It duplicates a string. It dinamically allocates memory for a new string 
*into the allocated memory and returns a pointer to the new string.
*/
char	*ft_strdup(const char *str)
{
	size_t			len;
	char			*new_str;

	len = ft_strlen(str) + 1;
	new_str = (char *)malloc(len * sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str, len);
	return (new_str);
}
