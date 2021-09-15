/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:46:28 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 01:34:40 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hook_map_c(t_game *game, int j, int i)
{
	draw_img(game, game->img_collect, j, i);
	game->collectable++;
}

void	hook_map_p(t_game *game, int j, int i)
{
	draw_img(game, game->img_player, j, i);
	game->x = j;
	game->y = i;
}

void	hook_render_map_p(t_game *game, int j, int i)
{
	draw_img(game, game->img_player, j, i);
	game->x = j;
	game->y = i;
}
