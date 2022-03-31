/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:35:24 by hzona             #+#    #+#             */
/*   Updated: 2021/12/15 16:51:29 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printres(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (file->arr[i])
	{
		j = 0;
		while (file->arr[i][j])
		{
			printf ("%3c", file->arr[i][j]);
			j++;
		}
		printf ("\n");
		i++;
	}
}

int	init_game_map(int argc, char **argv, t_game *game)
{
	if (argc == 1 || check_file_name(argv[1]) == 0)
		return (file_name_error());
	game->file = read_file (argv[1], game->file, 1);
	if (check_map(game->file) == 0)
		return (1);
	init_window(game);
	game->up = 0;
	game->right = 0;
	game->left = 0;
	game->moves = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_game_map(argc, argv, &game) != 0)
		return (1);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (mlx_error());
	game.frames_m = 0;
	game.mlx_win = new_window(game.mlx, game.width, game.height, "so_long");
	mlx_hook(game.mlx_win.reference, 2, 0, ft_input, (void *)&game);
	mlx_loop_hook(game.mlx, *ft_update, (void *)&game);
	mlx_loop(game.mlx);
	free_arr(game.file);
}
