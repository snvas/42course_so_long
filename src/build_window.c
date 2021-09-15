/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:00:45 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 01:27:35 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	build_window(t_game *game)
{
	get_window_size(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->win_width, game->win_height, "so_long");
	game->moves = 0;
	game->collected = 0;
	game->collectable = 0;
}
