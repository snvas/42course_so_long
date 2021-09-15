/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:32:35 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 18:45:12 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_chars(char **map)
{
	int	height;
	int	width;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] != '0' && map[height][width] != '1'
				&& map[height][width] != 'C'
				&& map[height][width] != 'E'
				&& map[height][width] != 'P')
				return (0);
			width++;
		}
		height++;
	}
	return (1);
}

static int	check_positions(char **map, t_map *m)
{
	int	height;
	int	width;

	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[height][width] == 'E')
				m->exit_count++;
			if (map[height][width] == 'P')
				m->ground_count++;
			if (map[height][width] == 'C')
				m->to_collect_count++;
			width++;
		}
		height++;
	}
	if (m->exit_count != 1 || m->ground_count != 1 || m->to_collect_count == 0)
		return (0);
	return (1);
}

static int	check_walls(char **map, t_map *m)
{
	int	height;
	int	width;

	m->width = ft_strlen(map[0]);
	m->height = 0;
	while (map[m->height])
		m->height++;
	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (map[0][width] != '1' || map[m->height - 1][width] != '1'
				|| map[height][0] != '1' || map[height][m->width - 1] != '1')
				return (0);
			width++;
		}
		if (width != m->width)
			return (0);
		height++;
	}
	return (1);
}

static int	isber(char *file)
{
	char	*ext;

	if (!file)
		return (0);
	ext = ft_strrchr(file, '.');
	if (ft_strncmp(ext, ".ber", 5))
		return (0);
	return (1);
}

int	check_map(char **map, char *file)
{
	t_map	m;

	t_map_init(&m);
	if (map)
		if (isber(file) && check_chars(map)
			&& check_positions(map, &m) && check_walls(map, &m))
			return (1);
	return (0);
}
