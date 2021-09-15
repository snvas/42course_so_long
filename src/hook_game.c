/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:06:25 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 00:06:42 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hook_game(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_DESTROY_NOTIFY, 0, &exit_game, game);
	mlx_hook(game->win, X_EVENT_FOCUS_IN, 1L << 21, &render_map, game);
}
