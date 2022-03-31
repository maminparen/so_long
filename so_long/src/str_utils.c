/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:05:45 by hzona             #+#    #+#             */
/*   Updated: 2021/11/02 18:43:04 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*tmp;

	tmp = (char *)str;
	i = 0;
	while (str[i])
	{
		if ((char)ch == str[i])
			return (&tmp[i]);
		i++;
	}
	if ((char)ch == '\0')
		return (&tmp[i]);
	return ((void *)0);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	res = (char *) malloc(len + 1);
	if (res == (void *)0)
		return ((void *)0);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		k;

	if (!s1 && !s2)
		return ((void *)0);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == (void *)0 || !s1 || !s2)
		return ((void *)0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		res[i + k] = s2[k];
		k++;
	}
	res[i + k] = '\0';
	if (s1)
		free (s1);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	if (!s)
		return ((void *)0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (res == (void *)0)
		return ((void *)0);
	while (i < len)
	{
		if (s[start + i] != '\0' && start < ft_strlen(s))
			res[i] = s[start + i];
		else
			res[i] = '\0';
		i++;
	}
	res[i] = '\0';
	return (res);
}
