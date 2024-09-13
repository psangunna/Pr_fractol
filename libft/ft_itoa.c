/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:06:55 by pamela            #+#    #+#             */
/*   Updated: 2024/04/15 12:43:31 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
It counts the number of digits of a integer.
*/
static int	get_number_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

/*
*It fills the result string with the integer converted to string
*/
static void	fill_result_string(int size, int offset, int n, char *result)
{
	while (size > offset)
	{
		result[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

/*
Main function is used to convert an integer (of type int) into a string 
(array of characters) representation. It stands for "integer to ASCII". 
This function takes an integer as input and returns a dynamically allocated 
string that represents that integer.
*/
char	*ft_itoa(int n)
{
	int		offset;
	int		size;
	char	*result;

	offset = 0;
	size = get_number_size(n);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (0);
	if (n == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		n = 147483648;
		offset = 2;
	}
	if (n < 0)
	{
		result[0] = '-';
		offset = 1;
		n = -n;
	}
	fill_result_string(size, offset, n, result);
	result[size] = '\0';
	return (result);
}
