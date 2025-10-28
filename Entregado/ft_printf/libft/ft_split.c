/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:23:31 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 04:23:32 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_segments(const char *s, char delimiter)
{
	size_t	count;
	int		in_segment;

	count = 0;
	in_segment = 0;
	while (*s)
	{
		if (*s != delimiter && !in_segment)
		{
			in_segment = 1;
			count++;
		}
		else if (*s == delimiter)
			in_segment = 0;
		s++;
	}
	return (count);
}

static char	**free_words(char **words, size_t count)
{
	while (count > 0)
		free(words[--count]);
	free(words);
	return (NULL);
}

static char	*extract_word(const char **cursor, char delimiter)
{
	const char	*start;
	size_t		length;
	char		*word;

	start = *cursor;
	length = 0;
	while ((*cursor)[length] && (*cursor)[length] != delimiter)
		length++;
	word = (char *)malloc(length + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, length);
	word[length] = '\0';
	*cursor += length;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char const	*cursor;
	char		**words;
	size_t		word_count;
	size_t		index;

	if (!s)
		return (NULL);
	word_count = count_segments(s, c);
	words = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!words)
		return (NULL);
	cursor = s;
	index = 0;
	while (index < word_count)
	{
		while (*cursor == c)
			cursor++;
		words[index] = extract_word(&cursor, c);
		if (!words[index])
			return (free_words(words, index));
		index++;
	}
	return (words);
}
