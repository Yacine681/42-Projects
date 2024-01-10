/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:06:26 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

int	check_map_1(t_game *game)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	a = 0;
	j = 0;
	while (game->map[j])
		j++;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if ((game->map[0][a] != '1' || game->map[j - 1][a] != '1' ||
					game->map[i][0] != '1') || (game->map[i][a + 1] == '\n'
						&& game->map[i][a] != '1'))
				return (1);
			a++;
		}
		a = 0;
		i++;
	}
	return (0);
}

int	check_map_2(t_game *game)
{
	int	i;
	int	a;
	int	j;
	int	b;

	i = 0;
	a = 0;
	j = 0;
	b = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\0')
		{
			if (game->map[i][a] == 'P')
				j++;
			if (game->map[i][a] == 'E')
				b++;
			a++;
		}
	a = 0;
	i++;
	}
	if (j > 1 || j == 0 || b == 0 || b > 1)
		return (1);
	return (0);
}

int	check_map_3(t_game *game)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	a = 0;
	j = 0;
	while (game->map[i])
		i++;
	while (game->map[j][a])
		a++;
	if (a == i + 1)
		return (1);
	return (0);
}

int	check_map_4(t_game *game)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	a = 0;
	j = 0;
	while (game->map[i][a])
		a++;
	while (game->map[i])
	{
		while (game->map[i][j])
			j++;
		if (j != a)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

int	check_map_5(t_game *game)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	a = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\0')
		{
			if (game->map[i][a] == 'C')
				j++;
			a++;
		}
	a = 0;
	i++;
	}
	if (j == 0)
		return (1);
	return (0);
}
