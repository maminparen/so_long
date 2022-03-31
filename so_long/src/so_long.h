/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:57:21 by hzona             #+#    #+#             */
/*   Updated: 2021/12/15 16:51:20 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# define BORDER 49 
# define FRE_P 48
# define END 69
# define PLAYER 80
# define STUPID 81
# define HARD_H 82
# define HARD_W 83
# define IMBA 84
# define LOOT 67

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_enemy
{
	int				type;
	int				index;
	int				x;
	int				y;
	int				up;
	int				down;
	int				right;
	int				left;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}		t_image;

typedef struct s_file
{
	int		width;
	int		height;
	char	**arr;
	char	*line;

	int		loot;
	int		max_enemy;
	t_enemy	*enemy;
}		t_file;

typedef struct s_game
{
	void		*mlx;
	t_window	mlx_win;
	t_image		*sprite;
	int			h_count;
	int			w_count;
	int			width;
	int			height;
	int			left;
	int			moves;
	int			up;
	int			right;
	int			frames_m;

	t_file		*file;

}		t_game;

char		**ft_split(char const *s, char c);

char		*ft_strdup(const char *str);
char		*ft_strchr(const char *str, int ch);
char		*ft_strjoin(char *s1, char const *s2);
size_t		ft_strlen(const char *string);
char		*ft_substr(char const *s, unsigned int start, size_t len);

int			check_file_name(char *str);
int			check_all_len(char **arr, int *p_w, int *p_h);
int			check_border(char **arr, int width, int height);
int			check_player_end(char **arr, int height, int *p_loot);
int			check_valid_sym(char **arr, int width, int height);

t_file		*read_file(char *file_name, t_file *new, int read_b);
int			check_map(t_file *file);
int			free_arr(t_file *file);

int			file_name_error(void);
int			mlx_error(void);
t_file		*file_error(void);

void		init_window(t_game *game);
t_window	new_window(void *mlx, int widht, int height, char *name);

void		init_windows_sprite(t_game *game);
int			ft_close(void);
int			ft_update(void *param);

t_image		ft_new_sprite(void *mlx, char *path);

int			ft_input(int key, t_game *game);

int			is_enemy(char c);
char		*ft_itoa(int n);
void		check_player_position(t_game *game);
void		hero_image(t_game *game, int move);
void		enemy_image(t_game *game, int move);
void		loot_image(t_game *game, int move);
void		end_image(t_game *game);

t_enemy		*init_new_enemy(int type, int i, int j, int index);
void		add_enemy_back(t_enemy *old, t_enemy *new);
void		move_right_left(t_game *game, int move, int i, int j);

void		move_enemy(t_game *game);
void		background_image(t_game *game);
void		wall_image(t_game *game);

void		find_player_coord(t_game *game, int *p_i, int *p_j);
void		move_up_down(t_game *game, int move, int i, int j);

#endif
