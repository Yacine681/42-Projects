/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:18:19 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

void	put_exit(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if (game->map[i][a] == 'E' && (!verif_items(game)))
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm",
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

void	put_exit_win(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if (game->map[i][a] == 'E' && verif_items(game))
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "xpm/exit_win.xpm",
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

void	put_enemy(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		while (game->map[i][a] != '\n')
		{
			if (game->map[i][a] == 'M')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "xpm/enemy.xpm",
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
