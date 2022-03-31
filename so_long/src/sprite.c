/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:00:12 by hzona             #+#    #+#             */
/*   Updated: 2021/12/15 16:50:41 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

static void	draw_text(t_game *game)
{
	char	*str;
	int		tmp;

	tmp = (game->width - 30);
	str = ft_itoa(game->frames_m);
	mlx_string_put(game->mlx, game->mlx_win.reference, tmp, 24, -1, str);
	free(str);
}

int	ft_update(void *param)
{
	t_game		*game;
	static int	frame;
	static int	move;

	game = (t_game *)param;
	frame++;
	game->frames_m ++;

	if (frame == 10)
		move += 1;
	else if (frame >= 20)
	{
		move -= 1;
		frame = 0;
	}
	background_image(game);
	wall_image(game);
	end_image(game);
	loot_image(game, move);
	enemy_image(game, move);
	hero_image(game, move);
	draw_text(game);
	return (0);
}
