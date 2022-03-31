/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:46:00 by hzona             #+#    #+#             */
/*   Updated: 2021/11/02 19:17:05 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_right_up(t_enemy *tmp, int i)
{
	if (tmp->left == 0 && tmp->right == 0 && tmp->up == 0 && tmp->down == 0)
	{
		i = rand() % 2;
		if (i == 1 && tmp->type == HARD_H)
			tmp->right = 1;
		else if (tmp->type == HARD_H)
			tmp->right = -1;
		else if (i == 1 && tmp->type == HARD_W)
			tmp->up = 1;
		else if (tmp->type == HARD_W)
			tmp->up = -1;
	}
}

void	start_move(t_game *game, t_enemy *tmp, int i)
{
	check_right_up(tmp, i);
	game->file->arr[tmp->y][tmp->x] = '0';
	if (game->file->arr[tmp->y + tmp->up][tmp->x + tmp->right] == PLAYER)
	{
		game->file->arr[tmp->y + tmp->up][tmp->x + tmp->right] = tmp->type;
		exit (0);
	}
	if (game->file->arr[tmp->y + tmp->up][tmp->x + tmp->right] == BORDER
		|| game->file->arr[tmp->y + tmp->up][tmp->x + tmp->right] == END
		|| game->file->arr[tmp->y + tmp->up][tmp->x + tmp->right] == LOOT
		|| is_enemy(game->file->arr[tmp->y + tmp->up][tmp->x + tmp->right]))
	{
		tmp->up = 0;
		tmp->right = 0;
	}
	tmp->y = tmp->y + tmp->up;
	tmp->x = tmp->x + tmp->right;
	game->file->arr[tmp->y][tmp->x] = tmp->type;
}

void	move_enemy(t_game *game)
{
	t_enemy	*tmp;

	tmp = game->file->enemy;
	while (tmp)
	{
		if (tmp->type == HARD_H || tmp->type == HARD_W)
			start_move(game, tmp, 0);
		tmp = tmp->next;
	}
}

void	find_player_coord(t_game *game, int *p_i, int *p_j)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height / 64)
	{
		j = 0;
		while (j < game->width / 64)
		{
			if (game->file->arr[i][j] == PLAYER)
			{
				*p_i = i;
				*p_j = j;
				game->file->arr[i][j] = 0;
			}
			j++;
		}
		i++;
	}
}

void	move_up_down(t_game *game, int move, int i, int j)
{
	if (game->file->arr[i + move][j] == END && game->file->loot == 0)
		return (exit(0));
	if (is_enemy(game->file->arr[i + move][j]))
		return (exit(0));
	if (game->file->arr[i + move][j] == LOOT)
		game->file->loot --;
	game->file->arr[i + move][j] = PLAYER;
	move_enemy(game);
	game->moves ++;
	printf("Moves-> %d\n", game->moves);
}
