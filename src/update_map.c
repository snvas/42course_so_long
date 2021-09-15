/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:06:25 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 16:35:42 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	updater_map(t_game *game)
{
	int		height;
	int		width;

	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				draw_img(game, game->img_wall, width, height);
			else if (game->map[height][width] == '0')
				draw_img(game, game->img_ground, width, height);
			else if (game->map[height][width] == 'C')
				draw_img(game, game->img_collect, width, height);
			else if (game->map[height][width] == 'E')
				draw_img(game, game->img_exit, width, height);
			else if (game->map[height][width] == 'P')
				hook_render_map_p(game, width, height);
			width++;
		}
		height++;
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
