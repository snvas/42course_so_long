/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:00:56 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 18:45:28 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_window_size(t_game *game)
{
	int	i;

	i = 0;
	game->win_width = ft_strlen(game->map[i]) * SPRITE_SIZE;
	game->win_height = 0;
	while (game->map[i])
	{
		game->win_height++;
		i++;
	}
	game->win_height *= SPRITE_SIZE;
}
