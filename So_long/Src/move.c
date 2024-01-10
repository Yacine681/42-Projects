/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:41:33 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

void	ft_move_w(t_game *game)
{
	find_player(game);
	if (win_w(game))
		exit_game(game);
	if (game->map[game->y - 1][game->x] != '1'
			&& game->map[game->y - 1][game->x] != 'E')
	{
		game->map[game->y][game->x] = '0';
		if (game->map[game->y - 1][game->x] == 'C')
			game->items--;
		if (game->map[game->y - 1][game->x] == 'M')
		{
			ft_printf(RED"%s\n", "Try Again! ಥ﹏ಥ");
			exit_game(game);
		}
		game->y--;
		game->map[game->y][game->x] = 'P';
		ft_printf("Move : %d\n", ++game->move);
	}
}

void	ft_move_a(t_game *game)
{
	find_player(game);
	if (win_a(game))
		exit_game(game);
	if (game->map[game->y + 1][game->x] != '1'
			&& game->map[game->y + 1][game->x] != 'E')
	{
		game->map[game->y][game->x] = '0';
		if (game->map[game->y + 1][game->x] == 'C')
			game->items--;
		if (game->map[game->y + 1][game->x] == 'M')
		{
			ft_printf(RED"%s\n", "Try Again! ಥ﹏ಥ");
			exit_game(game);
		}
		game->y++;
		game->map[game->y][game->x] = 'P';
		ft_printf("Move : %d\n", ++game->move);
	}
}

void	ft_move_s(t_game *game)
{
	find_player(game);
	if (win_s(game))
		exit_game(game);
	if (game->map[game->y][game->x - 1] != '1'
			&& game->map[game->y][game->x - 1] != 'E')
	{
		game->map[game->y][game->x] = '0';
		if (game->map[game->y][game->x - 1] == 'C')
			game->items--;
		if (game->map[game->y][game->x - 1] == 'M')
		{
			ft_printf(RED"%s\n", "Try Again! ಥ﹏ಥ");
			exit_game(game);
		}
		game->x--;
		game->map[game->y][game->x] = 'P';
		ft_printf("Move : %d\n", ++game->move);
	}
}

void	ft_move_d(t_game *game)
{
	find_player(game);
	if (win_d(game))
		exit_game(game);
	if (game->map[game->y][game->x + 1] != '1'
			&& game->map[game->y][game->x + 1] != 'E')
	{
		game->map[game->y][game->x] = '0';
		if (game->map[game->y][game->x + 1] == 'C')
			game->items--;
		if (game->map[game->y][game->x + 1] == 'M')
		{
			ft_printf(RED"%s\n", "Try Again! ಥ﹏ಥ");
			exit_game(game);
		}
		game->x++;
		game->map[game->y][game->x] = 'P';
		ft_printf("Move : %d\n", ++game->move);
	}
}
