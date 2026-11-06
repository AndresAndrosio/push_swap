/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:07:30 by jcervera          #+#    #+#             */
/*   Updated: 2026/10/24 01:18:02 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word_count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (word_count);
}

size_t	ft_word_len(const char *s, size_t start, char c)
{
	size_t	len;

	len = 0;
	while (s[start + len] != '\0' && s[start + len] != c)
		len++;
	return (len);
}

char	**ft_free_split(char **result, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_fill_split(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_len;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			word_len = ft_word_len(s, i, c);
			word = ft_substr(s, i, word_len);
			if (word == NULL)
				return (ft_free_split(result, j));
			result[j] = word;
			j++;
			i += word_len;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (s == NULL)
		return (NULL);
	word_count = ft_count_words(s, c);
	result = malloc(sizeof(*result) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	result = ft_fill_split(result, s, c);
	if (result == NULL)
		return (NULL);
	return (result);
}
