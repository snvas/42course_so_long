/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:42:14 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 23:45:13 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, img, x * SPRITE_SIZE, y * SPRITE_SIZE);
}
