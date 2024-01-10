/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:17:17 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

static	int	ft_strlen_height(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->height = i;
	return (i);
}

static	int	ft_strlen_length(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (game->map[i][a] != '\n')
		a++;
	game->length = a;
	return (a);
}

void	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, ft_strlen_length(game) * 50,
			ft_strlen_height(game) * 50, "So_long");
}

void	put_map(t_game *game)
{
	put_background(game);
	put_player(game);
	put_items(game);
	put_exit(game);
	put_exit_win(game);
	put_enemy(game);
}
