/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:18:42 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

static	void	initialisation(t_game *game)
{
	game->length = 0;
	game->height = 0;
	game->x = 0;
	game->y = 0;
	game->a = 0;
	game->b = 0;
	game->items = 0;
	game->move = 0;
	game->move1 = 0;
}

static	void	play(t_game *game)
{
	create_window(game);
	put_wall(game);
	put_background1(game);
	mlx_hook(game->win, 2, 2, press_key, game);
	mlx_hook(game->win, 17, 0L, exit_game, game);
	count_items(game);
	put_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	initialisation(&game);
	game.map = read_map(&argv[1]);
	if (argc != 2)
	{
		ft_printf("Error Argument!\n");
		exit (0);
	}
	else if (check_map(&game))
	{
		ft_printf("Error Map!\n");
		exit (0);
	}
	else if (check_ber(argv[1]))
	{
		ft_printf("Error .ber!\n");
		exit (0);
	}
	game.mlx = mlx_init();
	play(&game);
	mlx_string_put(game.mlx, game.win, 20, 25, 0xf8f8ff, "Move : ");
	mlx_string_put(game.mlx, game.win, 90, 25, 0xf8f8ff, ft_itoa(game.move));
	mlx_loop(game.mlx);
	return (0);
}
