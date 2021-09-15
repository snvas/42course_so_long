/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:50:22 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 16:31:18 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	build_img(t_game *game)
{
	game->img_ground = mlx_xpm_file_to_image
		(game->mlx, IMG_GROUND, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, IMG_WALL, &game->img_width, &game->img_height);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, IMG_COLLECT, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, IMG_EXIT, &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, IMG_PLAYER, &game->img_width, &game->img_height);
}
