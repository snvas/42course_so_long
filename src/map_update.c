/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:33:36 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/13 21:45:13 by snovaes          ###   ########.fr       */
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
		hold_w(game);
	else if (keycode == KEY_A || keycode == XK_Left)
		hold_a(game);
	else if (keycode == KEY_S || keycode == XK_Down)
		hold_s(game);
	else if (keycode == KEY_D || keycode == XK_Right)
		hold_d(game);
	else
		return ;
	map_updater(game);
}
