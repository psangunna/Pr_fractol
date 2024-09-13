/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:40:05 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 14:41:47 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *It converst a lowercase character to its corresponding uppercase character,
 *otherwise, it returns the character unchanged.
 */
int	ft_toupper(int c)
{
	int	val;

	val = 0;
	if (c >= 'a' && c <= 'z')
	{
		val = c - 32;
		return (val);
	}
	return (c);
}
