/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:00:45 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 02:06:15 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(t_game *game)
{
	get_window_size(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->win_width, game->win_height, "so_long");
	game->moves = 0;
	game->collected = 0;
	game->collectable = 0;
}
