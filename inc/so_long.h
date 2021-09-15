/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:05:49 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 01:44:55 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_space;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	void	*img_player;
	char	**map;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	int		moves;
	int		collected;
	int		collectable;
}	t_game;

typedef struct s_map
{
	int	col;
	int	row;
	int	exit_count;
	int	space_count;
	int	collectable_count;
}	t_map;

# define DEBUG 1

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define  X_EVENT_FOCUS_IN 9

# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define IMG_SPACE "img/grass.xpm"
# define IMG_WALL "img/tree.xpm"
# define IMG_COLLECT "img/rocks.xpm"
# define IMG_EXIT "img/exit.xpm"
# define IMG_PLAYER "img/player.xpm"

# define SPRITE_SIZE 40

char	**read_map(char *path_to_file);
int		check_map(char **map, char *file);
void	build_window(t_game *game);
void	get_window_size(t_game *game);
void	t_map_init(t_map *m);
void	build_map(t_game *game);
void	build_img(t_game *game);
void	draw_img(t_game *game, void *img, int x, int y);
int		press_key(int keycode, t_game *game);
void	update_map(int keycode, t_game *game);
void	change_position(char *pos, char *next_pos, char val, char new_val);

void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);

void	hook_map_c(t_game *game, int j, int i);
void	hook_map_p(t_game *game, int j, int i);
void	hook_render_map_p(t_game *game, int j, int i);
void	hook_game(t_game *game);
int		render_map(t_game *game);

void	ft_free_ptr(void **ptr);
void	free_map(char **map);
void	free_game(t_game *game);
int		exit_game(t_game *game);
#endif
