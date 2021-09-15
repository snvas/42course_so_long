/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:39:49 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 18:45:50 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(t_game *game)
{
	int		w;
	int		h;

	w = game->x;
	h = game->y;
	if (game->map[h][w + 1] == '0')
	{
		change_position(&game->map[h][w], &game->map[h][w + 1], '0', 'P');
		game->moves++;
	}
	else if (game->map[h][w + 1] == 'C')
	{
		change_position(&game->map[h][w], &game->map[h][w + 1], '0', 'P');
		game->moves++;
		game->myitens++;
	}
	else if (game->map[h][w + 1] == 'E' && (game->myitens == game->to_collect))
	{
		change_position(&game->map[h][w], &game->map[h][w + 1], '0', 'E');
		game->moves++;
		message_win(game);
		exit_game(game);
	}
	else
		return ;
}
