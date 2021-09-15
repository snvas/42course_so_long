/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:29:26 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 00:11:50 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	build_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_img(game, game->img_wall, j, i);
			else if (game->map[i][j] == '0')
				draw_img(game, game->img_space, j, i);
			else if (game->map[i][j] == 'C')
				hook_map_c(game, j, i);
			else if (game->map[i][j] == 'E')
				draw_img(game, game->img_exit, j, i);
			else if (game->map[i][j] == 'P')
				hook_map_p(game, j, i);
			j++;
		}
		i++;
	}
}

void	t_map_init(t_map *m)
{
	m->col = 0;
	m->row = 0;
	m->exit_count = 0;
	m->space_count = 0;
	m->collectable_count = 0;
}
