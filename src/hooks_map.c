/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:46:28 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 16:41:01 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hook_map_c(t_game *game, int width, int height)
{
	draw_img(game, game->img_collect, width, height);
	game->to_collect++;
}

void	hook_map_p(t_game *game, int width, int height)
{
	draw_img(game, game->img_player, width, height);
	game->x = width;
	game->y = height;
}

void	hook_render_map_p(t_game *game, int width, int height)
{
	draw_img(game, game->img_player, width, height);
	game->x = width;
	game->y = height;
}
