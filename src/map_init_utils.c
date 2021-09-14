/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:46:28 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/13 20:46:45 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_init_hook_c(t_game *game, int j, int i)
{
	img_draw(game, game->img_collect, j, i);
	game->collectable++;
}

void	map_init_hook_p(t_game *game, int j, int i)
{
	img_draw(game, game->img_player, j, i);
	game->x = j;
	game->y = i;
}