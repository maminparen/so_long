/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:03:29 by hzona             #+#    #+#             */
/*   Updated: 2021/11/02 19:16:14 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_arr(t_file *file)
{
	int	i;

	i = 0;
	if (file->arr)
	{
		while (file->arr[i])
		{
			free(file->arr[i]);
			i++;
		}
		free(file->arr);
	}
	if (file->line)
		free(file->line);
	if (file)
		free(file);
	exit(0);
	return (1);
}

t_file	*init_map(void)
{
	t_file	*map;

	map = malloc(sizeof(t_file));
	if (map == NULL)
		return (NULL);
	map->line = ft_strdup("");
	map->height = 0;
	map->width = 0;
	map->loot = 0;
	return (map);
}

t_file	*read_file(char *file_name, t_file *new, int read_b)
{
	int		fd;
	char	buffer[11];

	fd = open(file_name, O_RDONLY);
	if (!fd)
		return (NULL);
	new = init_map();
	while (read_b)
	{
		read_b = read(fd, buffer, 10);
		if (read_b < 0)
			return (file_error());
		buffer[read_b] = '\0';
		new->line = ft_strjoin(new->line, buffer);
	}
	if (!new->line)
		return (NULL);
	new->arr = ft_split(new->line, '\n');
	close(fd);
	return (new);
}

t_enemy	*init_new_enemy(int type, int i, int j, int index)
{
	t_enemy	*new;

	new = malloc(sizeof(t_enemy));
	if (!new)
		return (NULL);
	new->index = index;
	new->type = type;
	new->x = j;
	new->y = i;
	new->up = 0;
	new->left = 0;
	new->right = 0;
	new->down = 0;
	new->next = NULL;
	return (new);
}

void	add_enemy_back(t_enemy *old, t_enemy *new)
{
	t_enemy	*tmp;

	tmp = old;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
