/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:22:06 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/17 13:16:02 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Check if the character is a printable ASCII character 
(ASCII codes 32 to 126 inclusive)
If it's within this range, return 1 (true), otherwise return 0 (false)
*/
int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
	{
		return (1);
	}
	return (0);
}
