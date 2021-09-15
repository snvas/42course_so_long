/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:02:27 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 18:46:00 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	message_display(t_game *game)
{
	int	i;

	if (DEBUG)
	{
		i = 0;
		while (game->map[i])
		{
			printf("%s\n", game->map[i]);
			i++;
		}
		printf("collectable: %d\n", game->to_collect);
		printf("collected: %d\n", game->myitens);
	}
	printf("Movements: %d\n", game->moves);
	return (1);
}

int	message_win(t_game *game)
{
	printf("Item collection: %d\n", game->to_collect);
	printf("\\o/\\o/\\o/\\o/\\o/\\o/\\o/\\o/ Congratulations!!!\n");
	printf("--------------------------You WIN So Long!!\n");
	return (1);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		printf(" Game Closed!!\nI am sad you are leaving!");
		exit_game(game);
	}
	else
	{
		update_map(keycode, game);
		message_display(game);
	}
	return (0);
}
