/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:36:18 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 23:33:12 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	setbuf(stdout, NULL);
	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (check_map(game.map, argv[1]))
		{
			build_game(&game);
			build_img(&game);
			build_map(&game);
			game_hook(&game);
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
