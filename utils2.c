/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:25:44 by sciftci           #+#    #+#             */
/*   Updated: 2022/10/27 22:03:32 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cursor;

	if (n == 0)
		return (0);
	cursor = 0;
	while (cursor < (n - 1) && s1[cursor] && s2[cursor])
	{
		if (s1[cursor] != s2[cursor])
			break ;
		cursor++;
	}
	return (((unsigned char *)s1)[cursor] - ((unsigned char *)s2)[cursor]);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

unsigned int	count_words(const char *str, char sep)
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		if (*str == sep)
			str++;
		else
		{
			while (*str != sep && *str)
				str++;
			count++;
		}
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	char			**arr;
	unsigned int	words;
	unsigned int	i;

	if (!str)
		return (NULL);
	arr = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = -1;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			words = 0;
			while (*str != c && *str && ++words)
				str++;
			arr[++i] = (char *)malloc((words + 1) * sizeof(char));
			ft_strlcpy(arr[i], str - words, words + 1);
		}
	}
	return (arr);
}
