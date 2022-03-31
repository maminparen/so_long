/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:39:45 by hzona             #+#    #+#             */
/*   Updated: 2021/11/02 18:56:24 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_enemy(char c)
{
	if (c == STUPID)
		return (1);
	if (c == HARD_H)
		return (1);
	if (c == HARD_W)
		return (1);
	if (c == IMBA)
		return (1);
	return (0);
}

void	init_enemy(t_file *file)
{
	int		i;
	int		j;
	t_enemy	*new;

	i = -1;
	file->max_enemy = 0;
	while (++i < file->height)
	{
		j = -1;
		while (file->arr[i][++j])
		{
			if (is_enemy(file->arr[i][j]))
			{
				new = init_new_enemy(file->arr[i][j], i, j, file->max_enemy);
				file->max_enemy++;
				if (!file->enemy)
					file->enemy = new;
				else
					add_enemy_back(file->enemy, new);
			}
		}
	}
}

int	check_map(t_file *file)
{
	if (check_all_len(file->arr, &file->width, &file->height) == 0)
	{
		printf("Error: Карта не правильной формы.\n");
		return (0);
	}
	if (check_border(file->arr, file->width, file->height) == 0)
	{
		printf("Error: Карта не закрыта.\n");
		return (0);
	}
	if (check_valid_sym(file->arr, file->width, file->height) == 0)
	{
		printf("Error: Обнаружены не опознаные объекты на карте.\n");
		return (0);
	}
	if (check_player_end(file->arr, file->height, &file->loot) == 0)
	{
		printf("Error: Отсутствуют нужные объекты на карте");
		printf(", либо имеются дубли игрока/выхода.\n");
		return (0);
	}
	init_enemy(file);
	return (1);
}

void	move_right_left(t_game *game, int move, int i, int j)
{
	if (move < 0)
		game->left = 1;
	else
		game->left = 0;
	if (game->file->arr[i][j + move] == END && game->file->loot == 0)
		return (exit(0));
	if (is_enemy(game->file->arr[i][j + move]))
		return (exit(0));
	if (game->file->arr[i][j + move] == LOOT)
		game->file->loot --;
	game->file->arr[i][j + move] = PLAYER;
	move_enemy(game);
	game->moves ++;
	printf("Moves-> %d\n", game->moves);
}

int	ft_input(int key, t_game *game)
{
	int	i;
	int	j;

	find_player_coord(game, &i, &j);
	if (key == 53)
		return (free_arr(game->file));
	else if (key == 13 && (game->file->arr[i - 1][j] != BORDER)
	&& (game->file->arr[i - 1][j] != END || (game->file->arr[i - 1][j] == END
	&& game->file->loot == 0)))
		move_up_down(game, -1, i, j);
	else if (key == 1 && (game->file->arr[i + 1][j] != BORDER)
	&& (game->file->arr[i + 1][j] != END || (game->file->arr[i + 1][j] == END
	&& game->file->loot == 0)))
		move_up_down(game, 1, i, j);
	else if (key == 0 && (game->file->arr[i][j - 1] != BORDER)
	&& (game->file->arr[i][j - 1] != END || (game->file->arr[i][j - 1] == END
	&& game->file->loot == 0)))
		move_right_left(game, -1, i, j);
	else if (key == 2 && (game->file->arr[i][j + 1] != BORDER)
	&& (game->file->arr[i][j + 1] != END || (game->file->arr[i][j + 1] == END
	&& game->file->loot == 0)))
		move_right_left(game, 1, i, j);
	else
		game->file->arr[i][j] = PLAYER;
	return (0);
}
