/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:09:44 by hzona             #+#    #+#             */
/*   Updated: 2021/10/25 12:10:21 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	word_len(const char *str, char c)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] && str[i + 1] == c)
			|| (str[i] != c && !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static size_t	len_split(const char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**clean_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ((void *)0);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	size_t			start;
	char			**arr;

	i = 0;
	start = 0;
	if (!s)
		return ((void *)0);
	arr = malloc((word_len(s, c) + 1) * sizeof(char *));
	if (!arr)
		return ((void *)0);
	while (s[i++] == c)
		start++;
	i = -1;
	while (++i < word_len(s, c))
	{
		arr[i] = ft_substr(s, start, len_split(&s[start], c));
		if (!arr[i])
			return (clean_split(arr));
		start += len_split(&s[start], c);
		while (s[start] == c)
			start++;
	}
	arr[i] = (void *)0;
	return (arr);
}
