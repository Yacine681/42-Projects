/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:51:27 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:33:05 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_borde(char **map, int line, int column)
{
	if (map[line][column] != '1' && map[line][column] != ' ')
		return (1);
	return (0);
}

int	ft_check_borde2(char **map, int line, int index)
{
	while (map[line][index])
	{
		if (map[line][index] != '1' && map[line][index] != ' ')
			return (1);
		index++;
	}
	return (0);
}

int	chech_all_wall_closed(char **map, int line)
{
	int	li1;
	int	li2;

	li1 = ft_strlen(map[line]);
	li2 = 0;
	if (map[line + 1])
		li2 = ft_strlen(map[line + 1]);
	if (li1 > li2 && li2 > 0)
	{
		if (ft_check_borde2(map, line, li2))
			return (1);
	}
	else if (li2 > li1)
	{
		if (ft_check_borde2(map, line + 1, li1))
			return (1);
	}
	return (0);
}
