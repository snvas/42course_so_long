/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:03:34 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 21:51:10 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_window_size(t_game *game)
{
	int	i;

	i = 0;
	game->win_width = ft_strlen(game->map[i]) * SPRITE_SIZE;
	game->win_height = 0;
	while (game->map[i])
	{
		game->win_height++;
		i++;
	}
	game->win_height *= SPRITE_SIZE;
}

int	display_info(t_game *game)
{
	printf("Moviments: %d\n", game->moves);
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else
	{
		map_update(keycode, game);
		if (DEBUG)
			display_info(game);
	}
	return (0);
}

void	change_position(char *pos, char *next_pos, char val, char new_val)
{
	*pos = val;
	*next_pos = new_val;
}
