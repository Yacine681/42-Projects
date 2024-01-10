/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:18:05 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

void	put_background(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if (game->map[i][a] == '0' || game->map[i][a] == 'P')
			{
				game->img = mlx_xpm_file_to_image(game->mlx,
						"xpm/background.xpm", &game->b, &game->a);
				mlx_put_image_to_window(game->mlx, game->win, game->img,
					a * 50, i * 50);
			}
			a++;
		}
		a = 0;
		i++;
	}
}

void	put_background1(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if (game->map[i][a] != '1')
			{
				game->img = mlx_xpm_file_to_image(game->mlx,
						"xpm/background.xpm", &game->b, &game->a);
				mlx_put_image_to_window(game->mlx, game->win, game->img,
					a * 50, i * 50);
			}
			a++;
		}
		a = 0;
		i++;
	}
}

void	put_player(t_game *game)
{
	find_player(game);
	if (game->move1 % 2 == 0)
	{
		game->img = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm",
				&game->b, &game->a);
		mlx_put_image_to_window(game->mlx, game->win, game->img,
			game->x * 50, game->y * 50);
	}
	else
	{
		game->img = mlx_xpm_file_to_image(game->mlx, "xpm/player1.xpm",
				&game->b, &game->a);
		mlx_put_image_to_window(game->mlx, game->win, game->img,
			game->x * 50, game->y * 50);
	}
	game->move1++;
}

void	put_wall(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if (game->map[i][a] == '1')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "xpm/wall.xpm",
						&game->b, &game->a);
				mlx_put_image_to_window(game->mlx, game->win, game->img,
					a * 50, i * 50);
			}
			a++;
		}
		a = 0;
		i++;
	}
}

void	put_items(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if (game->map[i][a] == 'C')
			{
				game->img = mlx_xpm_file_to_image(game->mlx,
						"xpm/collectable.xpm", &game->b, &game->a);
				mlx_put_image_to_window(game->mlx, game->win, game->img,
					a * 50, i * 50);
			}
			a++;
		}
		a = 0;
		i++;
	}
}
