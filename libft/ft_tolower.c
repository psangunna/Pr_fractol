/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:42:06 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 14:43:39 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *It converst an uppercase character to its corresponding lowercase character,
 *otherwise, it returns the input character unchanged.
 */
int	ft_tolower(int c)
{
	int	val;

	val = 0;
	if (c >= 'A' && c <= 'Z')
	{
		val = c + 32;
		return (val);
	}
	return (c);
}
