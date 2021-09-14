/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:01:55 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/13 21:02:04 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_update_hook_p(t_game *game, int j, int i)
{
	img_draw(game, game->img_player, j, i);
	game->x = j;
	game->y = i;
}