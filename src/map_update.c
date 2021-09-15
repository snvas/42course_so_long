/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:33:36 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 17:09:05 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	map_updater(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				img_draw(game, game->img_wall, j, i);
			else if (game->map[i][j] == '0')
				img_draw(game, game->img_space, j, i);
			else if (game->map[i][j] == 'C')
				img_draw(game, game->img_collect, j, i);
			else if (game->map[i][j] == 'E')
				img_draw(game, game->img_exit, j, i);
			else if (game->map[i][j] == 'P')
				map_update_hook_p(game, j, i);
			j++;
		}
		i++;
	}
}

void	map_update(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == XK_Up)
		move_up(game);
	else if (keycode == KEY_A || keycode == XK_Left)
		move_left(game);
	else if (keycode == KEY_S || keycode == XK_Down)
		move_down(game);
	else if (keycode == KEY_D || keycode == XK_Right)
		move_right(game);
	else
		return ;
	map_updater(game);
}
