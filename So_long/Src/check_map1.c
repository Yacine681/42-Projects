/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:16:45 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

static	int	check_map_6(t_game *game)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	a = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if (game->map[i][a] != '1' && game->map[i][a] != '0'
					&& game->map[i][a] != 'C' && game->map[i][a] != 'M'
						&& game->map[i][a] != 'E' && game->map[i][a] != 'P')
				j++;
			a++;
		}
	a = 0;
	i++;
	}
	if (j != 0)
		return (1);
	return (0);
}

int	check_map(t_game *game)
{
	if (check_map_1(game) || check_map_2(game) || check_map_3(game)
		|| check_map_4(game) || check_map_5(game) || check_map_6(game))
		return (1);
	return (0);
}

int	check_ber(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i] != '.')
		i++;
	if (argv[i + 1] == 'b' && argv[i + 2] == 'e'
		&& argv[i + 3] == 'r' && argv[i + 4] == '\0')
		return (0);
	return (1);
}
