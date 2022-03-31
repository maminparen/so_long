/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:12:17 by hzona             #+#    #+#             */
/*   Updated: 2021/11/02 19:16:02 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'r')
		return (0);
	if (str[len - 2] != 'e')
		return (0);
	if (str[len - 3] != 'b')
		return (0);
	if (str[len - 4] != '.')
		return (0);
	return (1);
}

int	check_all_len(char **arr, int *p_w, int *p_h)
{
	int	i;
	int	first_len;

	i = 0;
	if (!arr || !arr[i])
		return (0);
	first_len = ft_strlen(arr[i]);
	while (arr[i])
	{
		if ((size_t)first_len != ft_strlen(arr[i]))
			return (0);
		i++;
	}
	*p_w = first_len;
	*p_h = i;
	return (1);
}

int	check_border(char **arr, int width, int height)
{
	int	i;

	i = 0;
	while (arr[0][i] == BORDER)
		i++;
	if (i != width)
		return (0);
	i = 0;
	while (arr[height - 1][i] == BORDER)
		i++;
	if (i != width)
		return (0);
	i = 0;
	while (i < height && arr[i][0] == BORDER)
		i++;
	if (i != height)
		return (0);
	i = 0;
	while (i < height && arr[i][width - 1] == BORDER)
		i++;
	if (i != height)
		return (0);
	return (1);
}

int	check_player_end(char **arr, int height, int *p_loot)
{
	int	i;
	int	j;
	int	marker_player;
	int	marker_end;

	i = -1;
	marker_player = 0;
	marker_end = 0;
	*p_loot = 0;
	while (++i < height)
	{
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][j] == PLAYER)
				marker_player ++;
			if (arr[i][j] == END)
				marker_end ++;
			if (arr[i][j] == LOOT)
				*p_loot = *p_loot + 1;
		}
	}
	if (marker_player == 1 && marker_end != 0 && *p_loot != 0)
		return (1);
	return (0);
}

int	check_valid_sym(char **arr, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (arr[i][j] != BORDER && arr[i][j] != END && arr[i][j] != LOOT
			&& arr[i][j] != PLAYER && arr[i][j] != FRE_P
			&& !is_enemy(arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
