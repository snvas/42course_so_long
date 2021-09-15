/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:09:37 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 16:20:55 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_game *game)
{
	int		w;
	int		h;

	w = game->x;
	h = game->y;
	if (game->map[h - 1][w] == '0')
	{
		change_position(&game->map[h][w], &game->map[h - 1][w], '0', 'P');
		game->moves++;
	}
	else if (game->map[h - 1][w] == 'C')
	{
		change_position(&game->map[h][w], &game->map[h - 1][w], '0', 'P');
		game->moves++;
		game->myitens++;
	}
	else if (game->map[h - 1][w] == 'E' && (game->myitens == game->to_collect))
	{
		change_position(&game->map[h][w], &game->map[h - 1][w], '0', 'E');
		game->moves++;
		message_win(game);
		exit_game(game);
	}
	else
		return ;
}
