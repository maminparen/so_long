/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:37:10 by hzona             #+#    #+#             */
/*   Updated: 2021/11/02 19:17:23 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->h_count = game->file->height;
	game->w_count = game->file->width;
	game->height = game->file->height * 64;
	game->width = game->file->width * 64;
}

int	ft_close(void)
{
	exit(0);
}

t_window	new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close, 0);
	return (window);
}

void	background_image(t_game *game)
{
	int		i;
	int		x;
	int		y;
	int		j;
	t_image	sprite;

	sprite = ft_new_sprite(game->mlx, "image/grasstile.xpm");
	i = 0;
	while (i * 64 < game->height)
	{
		y = 64 * i;
		j = 0;
		while (j * 64 < game->width)
		{
			x = 64 * j;
			mlx_put_image_to_window(game->mlx, game->mlx_win.reference,
				sprite.reference, x, y);
			j++;
		}
		i++;
	}
}

void	wall_image(t_game *game)
{
	int		i;
	int		x;
	int		y;
	int		j;
	t_image	sprite;

	sprite = ft_new_sprite(game->mlx, "image/border.xpm");
	i = 0;
	while (i * 64 < game->height)
	{
		y = 64 * i;
		j = 0;
		while (j * 64 < game->width)
		{
			x = 64 * j;
			if (game->file->arr[i][j] == BORDER)
				mlx_put_image_to_window(game->mlx, game->mlx_win.reference,
					sprite.reference, x, y);
			j++;
		}
		i++;
	}
}
