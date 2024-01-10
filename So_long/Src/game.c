/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:17:41 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	exit (0);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_game(game);
	else if (keycode == 13 || keycode == 126)
		ft_move_w(game);
	else if (keycode == 1 || keycode == 125)
		ft_move_a(game);
	else if (keycode == 0 || keycode == 123)
		ft_move_s(game);
	else if (keycode == 2 || keycode == 124)
		ft_move_d(game);
	else
		return (0);
	put_map(game);
	put_wall(game);
	mlx_string_put(game->mlx, game->win, 20, 25, 0xf8f8ff, "Move : ");
	mlx_string_put(game->mlx, game->win, 90, 25, 0xf8f8ff, ft_itoa(game->move));
	return (0);
}

void	find_player(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\0')
		{
			if (game->map[i][a] == 'P')
			{
				game->y = i;
				game->x = a;
			}
			a++;
		}
		a = 0;
		i++;
	}
}

void	count_items(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	game->items = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\0')
		{
			if (game->map[i][a] == 'C')
				game->items++;
			a++;
		}
	a = 0;
	i++;
	}
}

int	verif_items(t_game *game)
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
