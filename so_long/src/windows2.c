/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:47:06 by hzona             #+#    #+#             */
/*   Updated: 2021/12/25 16:55:44 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_image(t_game *game)
{
	int		i;
	int		x;
	int		y;
	int		j;
	t_image	sprite;

	if (game->file->loot == 0)
		sprite = ft_new_sprite(game->mlx, "image/revard.xpm");
	else
		sprite = ft_new_sprite(game->mlx, "image/revard_old.xpm");
	i = 0;
	while (i * 64 < game->height)
	{
		y = 64 * i;
		j = 0;
		while (j * 64 < game->width)
		{
			x = 64 * j;
			if (game->file->arr[i][j] == END)
				mlx_put_image_to_window(game->mlx, game->mlx_win.reference,
					sprite.reference, x, y);
			j++;
		}
		i++;
	}
}

void	loot_image(t_game *game, int move)
{
	int		i;
	int		x;
	int		y;
	int		j;
	t_image	sprite;

	sprite = ft_new_sprite(game->mlx, "image/loot.xpm");
	i = 0;
	while (i * 64 < game->height)
	{
		y = 64 * i + move;
		j = 0;
		while (j * 64 < game->width)
		{
			x = 64 * j - move;
			if (game->file->arr[i][j] == LOOT)
				mlx_put_image_to_window(game->mlx, game->mlx_win.reference,
					sprite.reference, x, y);
			j++;
		}
		i++;
	}
}

void	enemy_image(t_game *game, int move)
{
	int		i;
	int		x;
	int		y;
	int		j;
	t_image	sprite;

	sprite = ft_new_sprite(game->mlx, "image/enemy.xpm");
	i = 0;
	while (i * 64 < game->height)
	{
		y = 64 * i + move;
		j = 0;
		while (j * 64 < game->width)
		{
			x = 64 * j;
			if (is_enemy(game->file->arr[i][j]))
				mlx_put_image_to_window(game->mlx, game->mlx_win.reference,
					sprite.reference, x, y);
			j++;
		}
		i++;
	}
}

void	hero_image(t_game *game, int move)
{
	int		i;
	int		x;
	int		y;
	int		j;
	t_image	sprite;

	if (game->left == 1)
		sprite = ft_new_sprite(game->mlx, "image/hero_left.xpm");
	else
		sprite = ft_new_sprite(game->mlx, "image/hero.xpm");
	i = 0;
	while (i * 64 < game->height)
	{
		y = 64 * i + move;
		j = 0;
		while (j * 64 < game->width)
		{
			x = 64 * j;
			if (game->file->arr[i][j] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->mlx_win.reference,
					sprite.reference, x, y);
			j++;
		}
		i++;
	}
}

void	check_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->right == 0 && game->left == 0)
		return ;
	printf("right %d left %d", game->up, game->left);
	while (game->file->arr[i][j] != PLAYER && i < game->file->height / 64)
	{
		j = 0;
		while (game->file->arr[i][j] != PLAYER && i < game->file->width / 64)
			j++;
		i++;
	}
	game->file->arr[i][j] = '0';
	game->file->arr[i + game->up][j + game->right] = PLAYER;
}
