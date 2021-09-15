/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:55:28 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 22:14:54 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_hook(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_DESTROY_NOTIFY, 0, &exit_game, game);
	mlx_hook(game->win, X_EVENT_FOCUS_IN, 1L << 21, &map_resume, game);
}
