/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:02:27 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 00:05:04 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	display_info(t_game *game)
{
	printf("Moviments: %d\n", game->moves);
	return (1);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else
	{
		update_map(keycode, game);
		if (DEBUG)
			display_info(game);
	}
	return (0);
}
