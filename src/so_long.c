/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:36:18 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 02:06:53 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	setbuf(stdout, NULL);
	if (argc == 2)
	{
		game.map = map_gen(argv[1]);
		if (map_check(game.map))
		{
			init_game(&game);
			img_init(&game);
			map_init(&game);
			mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &game);
			mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 0, &exit_game, &game);
			mlx_loop(game.mlx);
		}
		else
		{
			printf("Error!\nInvalid map!\n");
			free_map(game.map);
			exit(0);
		}
	}
	else
		printf("No map specified.\n");
	return (0);
}
