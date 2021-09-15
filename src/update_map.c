/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:06:25 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 00:10:01 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	updater_map(t_game *game)
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
				draw_img(game, game->img_wall, j, i);
			else if (game->map[i][j] == '0')
				draw_img(game, game->img_space, j, i);
			else if (game->map[i][j] == 'C')
				draw_img(game, game->img_collect, j, i);
			else if (game->map[i][j] == 'E')
				draw_img(game, game->img_exit, j, i);
			else if (game->map[i][j] == 'P')
				hook_render_map_p(game, j, i);
			j++;
		}
		i++;
	}
}

void	update_map(int keycode, t_game *game)
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
	updater_map(game);
}
