/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:32:35 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/14 23:12:44 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	valid_positions(char **map, t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				m->exit_count++;
			if (map[i][j] == 'P')
				m->space_count++;
			if (map[i][j] == 'C')
				m->collectable_count++;
			j++;
		}
		i++;
	}
	if (m->exit_count != 1 || m->space_count != 1 || m->collectable_count == 0)
		return (0);
	return (1);
}

static int	valid_walls(char **map, t_map *m)
{
	int	i;
	int	j;

	m->col = ft_strlen(map[0]);
	m->row = 0;
	while (map[m->row])
		m->row++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' || map[m->row - 1][j] != '1'
				|| map[i][0] != '1' || map[i][m->col - 1] != '1')
				return (0);
			j++;
		}
		if (j != m->col)
			return (0);
		i++;
	}
	return (1);
}

static int	valid_extension(char *file)
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
		if (valid_positions(map, &m) && valid_walls(map, &m)
			&& valid_map(map) && valid_extension(file))
			return (1);
	return (0);
}
