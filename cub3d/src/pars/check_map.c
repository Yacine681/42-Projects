/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:50:52 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:33:25 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_esp(char **map, int line, int colonne)
{
	if (map[line][colonne + 1] == ' ' || \
		map[line][colonne -1] == ' ' || \
		map[line + 1][colonne] == ' ' || \
		map[line -1][colonne] == ' ')
		exit_error("Invalid Map\n", 1);
	return (0);
}

int	check_maps(char **map)
{
	int	line;
	int	column;
	int	find;

	line = 0;
	find = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column] > 0)
		{
			if (!ft_set_char(map[line][column], " 01NSEW"))
				exit_error("Invalid Map: Character\n", 1);
			if (ft_set_char(map[line][column], "NSEW") \
			&& !ft_check_esp(map, line, column))
				find++;
			column++;
		}
		line++;
	}
	if (!find)
		exit_error("Invalid Map: Player\n", 1);
	else if (find > 1)
		exit_error("No Multiplayer Game\n", 1);
	return (0);
}

int	check_map_2(t_parma *map, int line, int column)
{
	if ((line == 0 && ft_check_borde(map->map.map, line, column)) \
		|| (line == map->map.line - 1 && \
		ft_check_borde(map->map.map, line, column)))
		exit_error("Invalid Map\n", 1);
	else if (column == 0 && ft_check_borde(map->map.map, line, column))
		exit_error("Inavlid Map\n", 1);
	else if (column == ft_strlen(map->map.map[line]) - 1 && \
		ft_check_borde(map->map.map, line, column))
		exit_error("Invalid Map\n", 1);
	else if ((line > 0 && line < map->map.line - 1) \
			&& (column > 0 && column < ft_strlen(map->map.map[line]) - 1))
	{
		if (map->map.map[line][column] == '0' && \
			(map->map.map[line + 1][column] == ' ' \
			|| map->map.map[line - 1][column] == ' ' \
			|| map->map.map[line][column + 1] == ' ' \
			|| map->map.map[line][column - 1] == ' '))
			exit_error("Invalid Map\n", 1);
	}
	return (0);
}

int	check_all_map(t_parma *parma)
{
	int	line;
	int	column;

	line = 0;
	while (parma->map.map[line])
	{
		column = 0;
		if (chech_all_wall_closed(parma->map.map, line))
			exit_error("Invalid Map It Don't Be Close\n", 1);
		while (parma->map.map[line][column])
		{
			check_map_2(parma, line, column);
			column++;
		}
		line++;
	}
	return (0);
}
