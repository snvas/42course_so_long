/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:29:26 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 23:30:58 by snovaes          ###   ########.fr       */
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
				img_draw(game, game->img_wall, j, i);
			else if (game->map[i][j] == '0')
				img_draw(game, game->img_space, j, i);
			else if (game->map[i][j] == 'C')
				map_init_hook_c(game, j, i);
			else if (game->map[i][j] == 'E')
				img_draw(game, game->img_exit, j, i);
			else if (game->map[i][j] == 'P')
				map_init_hook_p(game, j, i);
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
