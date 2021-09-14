/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_w.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:09:37 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 00:19:38 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hold_w(t_game *game)
{
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	if (game->map[y - 1][x] == '0')
	{
		change_position(&game->map[y][x], &game->map[y - 1][x], '0', 'P');
		game->moves++;
	}
	else if (game->map[y - 1][x] == 'C')
	{
		change_position(&game->map[y][x], &game->map[y - 1][x], '0', 'P');
		game->moves++;
		game->collected++;
	}
	else if (game->map[y - 1][x] == 'E'
		&& (game->collected == game->collectable))
	{
		change_position(&game->map[y][x], &game->map[y - 1][x], '0', 'E');
		game->moves++;
		exit_game(game);
	}
	else
		return ;
}