/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:03:34 by snovaes           #+#    #+#             */
/*   Updated: 2021/09/15 18:45:09 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_position(char *pos, char *next_pos, char val, char new_val)
{
	*pos = val;
	*next_pos = new_val;
}
