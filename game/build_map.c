/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:29:26 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 18:45:01 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	build_map(t_game *game)
{
	int		height;
	int		width;

	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				draw_img(game, game->img_wall, width, height);
			else if (game->map[height][width] == '0')
				draw_img(game, game->img_ground, width, height);
			else if (game->map[height][width] == 'C')
				hook_map_c(game, width, height);
			else if (game->map[height][width] == 'E')
				draw_img(game, game->img_exit, width, height);
			else if (game->map[height][width] == 'P')
				hook_map_p(game, width, height);
			width++;
		}
		height++;
	}
}

void	t_map_init(t_map *m)
{
	m->width = 0;
	m->height = 0;
	m->exit_count = 0;
	m->ground_count = 0;
	m->to_collect_count = 0;
}
