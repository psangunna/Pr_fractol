/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:44:16 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 14:24:51 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 *It fills the first n bytes of the object pointed with zero (null)
 */
void	ft_bzero(void *ptr, size_t n)
{
	ft_memset(ptr, '\0', n);
}
