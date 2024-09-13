/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psangunna <psanguna@student.42madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:58:10 by psangunna         #+#    #+#             */
/*   Updated: 2024/08/04 17:58:34 by psangunna        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

/* Helper function to manage a quoted substring within a string, accounting
for single quotes and a specified delimiter */
static size_t	handle_quotes(const char *str, char delimiter)
{
	size_t	length;

	length = 0;
	if (str[length] == '\'')
	{
		length++;
		while (str[length] && !(str[length] == '\'' && \
					(str[length + 1] == delimiter || str[length + 1] == '\0')))
		{
			length++;
		}
		if (str[length] == '\'')
			length++;
	}
	return (length);
}

/* Helper function to count how many words are in the string */
static size_t	count_words(char const *str, char delimiter)
{
	size_t	word_count;
	size_t	index;

	word_count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] != delimiter)
		{
			word_count++;
			if ((str[index]) == '\'')
				index += handle_quotes(&str[index], delimiter);
			while (str[index] && str[index] != delimiter)
				index++;
		}
		else if (str[index] == delimiter)
			index++;
	}
	return (word_count);
}

/* Helper function to get the works and save them into the array */
static char	*get_word(const char *str, unsigned int start, char delimiter,
		size_t *word_length)
{
	size_t		length;
	const char	*current;
	int			quotes;

	length = 0;
	quotes = 0;
	current = &str[start];
	if (current[length] == '\'')
	{
		length = handle_quotes(current, delimiter);
		quotes = 1;
	}
	while (current[length] && current[length] != delimiter)
		length++;
	if (word_length)
		*word_length = length;
	if (quotes == 1)
	{
		start = start + 1;
		length = length -2;
	}
	return (ft_substr(str, start, length));
}

/* Helper function to split a string into an array of substrings */
static char	**split_string(char const *str, char delimiter,
		char **array, size_t word_count)
{
	size_t	str_index;
	size_t	array_index;
	size_t	word_length;

	str_index = 0;
	array_index = 0;
	while (array_index < word_count)
	{
		while (str[str_index] && str[str_index] == delimiter)
			str_index++;
		array[array_index] = get_word(str, str_index, delimiter, &word_length);
		if (!array[array_index])
		{
			while (array_index-- > 0)
				free(array[array_index]);
			free(array);
			return (0);
		}
		str_index += word_length;
		array_index++;
	}
	array[array_index] = NULL;
	return (array);
}

/* Main function to split a string into an array of substrings */
char	**ft_split(char const *str, char delimiter)
{
	char	**array;
	size_t	word_count;

	if (!str)
		return (0);
	word_count = count_words(str, delimiter);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (0);
	array = split_string(str, delimiter, array, word_count);
	return (array);
}
