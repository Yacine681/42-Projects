/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:40:33 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

int	win_w(t_game *game)
{
	if (verif_items(game))
	{
		if (game->map[game->y - 1][game->x] != '1')
		{
			if (game->map[game->y - 1][game->x] == 'E')
			{
				game->map[game->y][game->x] = '0';
				ft_printf("Move : %d\n", ++game->move);
				ft_printf(GREEN"%s\n", "YOU WON! ( ͡° ͜ʖ ͡°)");
				return (1);
			}
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x] = 'P';
		}
	}
	return (0);
}

int	win_a(t_game *game)
{
	if (verif_items(game))
	{
		if (game->map[game->y + 1][game->x] != '1')
		{
			if (game->map[game->y + 1][game->x] == 'E')
			{
				game->map[game->y][game->x] = '0';
				ft_printf("Move : %d\n", ++game->move);
				ft_printf(GREEN"%s\n", "YOU WON! ( ͡° ͜ʖ ͡°)");
				return (1);
			}
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x] = 'P';
		}
	}
	return (0);
}

int	win_s(t_game *game)
{
	if (verif_items(game))
	{
		if (game->map[game->y][game->x - 1] != '1')
		{
			if (game->map[game->y][game->x - 1] == 'E')
			{
				game->map[game->y][game->x] = '0';
				ft_printf("Move : %d\n", ++game->move);
				ft_printf(GREEN"%s\n", "YOU WON! ( ͡° ͜ʖ ͡°)");
				return (1);
			}
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x] = 'P';
		}
	}
	return (0);
}

int	win_d(t_game *game)
{
	if (verif_items(game))
	{
		if (game->map[game->y][game->x + 1] != '1')
		{
			if (game->map[game->y][game->x + 1] == 'E')
			{
				game->map[game->y][game->x] = '0';
				ft_printf("Move : %d\n", ++game->move);
				ft_printf(GREEN"%s\n", "YOU WON! ( ͡° ͜ʖ ͡°)");
				return (1);
			}
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x] = 'P';
		}
	}
	return (0);
}
