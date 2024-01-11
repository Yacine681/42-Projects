/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:48:20 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:31:43 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free(t_parma *game, char *msg)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	free(game->map.filename);
	mlx_destroy_window(game->mlx, game->win_ptr);
	printf("%s\n", msg);
	exit(EXIT_SUCCESS);
}

int	ft_close(t_parma *game)
{
	ft_free(game, "Window Closed");
	return (0);
}

void	ft_new_window(t_parma *game)
{
	game->win_ptr = mlx_new_window(game->mlx, game->screen_w, game->screen_h, \
		"cub3D");
	mlx_hook(game->win_ptr, 17, 0, ft_close, game);
}

int	main(int ac, char *av[])
{
	t_parma	ptr;

	if (ac != 2)
		exit_error("Error! format: ./cub3d [map.cub]\n", 0);
	init_game(&ptr);
	ptr.map.filename = ft_strdup(av[1]);
	get_map_path(av[1], &ptr);
	start_game(&ptr);
	start_scane(&ptr);
	mlx_hook (ptr.win_ptr, 2, 0, &press, &ptr);
	mlx_hook (ptr.win_ptr, 3, 0, &release, &ptr);
	mlx_loop_hook(ptr.mlx, start_scane, &ptr);
	mlx_loop_hook(ptr.mlx, mini_map, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
