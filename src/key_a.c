/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:34:54 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 00:18:26 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hold_a(t_game *game)
{
	int		x;
	int		y;

	x = game->x;
	y = game->y;
	if (game->map[y][x - 1] == '0')
	{
		change_position(&game->map[y][x], &game->map[y][x - 1], '0', 'P');
		game->moves++;
	}
	else if (game->map[y][x - 1] == 'C')
	{
		change_position(&game->map[y][x], &game->map[y][x - 1], '0', 'P');
		game->moves++;
		game->collected++;
	}
	else if (game->map[y][x - 1] == 'E'
		&& (game->collected == game->collectable))
	{
		change_position(&game->map[y][x], &game->map[y][x - 1], '0', 'E');
		game->moves++;
		exit_game(game);
	}
	else
		return ;
}