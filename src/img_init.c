/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:50:22 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/13 21:19:19 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	img_init(t_game *game)
{
	game->img_space = mlx_xpm_file_to_image
		(game->mlx, IMG_SPACE, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, IMG_WALL, &game->img_width, &game->img_height);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, IMG_COLLECT, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, IMG_EXIT, &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, IMG_PLAYER, &game->img_width, &game->img_height);
}