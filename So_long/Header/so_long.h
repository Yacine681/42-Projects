/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:28:20 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:11:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../Printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"

typedef struct game
{
	void	*mlx;
	void	*win;
	void	*img;

	int		x;
	int		y;
	int		a;
	int		b;
	int		move;
	int		move1;
	int		items;
	int		length;
	int		height;

	char	**map;
}			t_game;

int		check_ber(char *argv);
int		check_map(t_game *game);
int		exit_game(t_game *game);
int		verif_items(t_game *game);
int		press_key(int keycode, t_game *game);

int		win_w(t_game *game);
int		win_a(t_game *game);
int		win_s(t_game *game);
int		win_d(t_game *game);

int		check_map_1(t_game *game);
int		check_map_2(t_game *game);
int		check_map_3(t_game *game);
int		check_map_4(t_game *game);
int		check_map_5(t_game *game);

void	put_map(t_game *game);
void	put_wall(t_game *game);
void	put_exit(t_game *game);
void	put_map(t_game *game);
void	ft_move_w(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);
void	put_items(t_game *game);
void	put_enemy(t_game *game);
void	put_player(t_game *game);
void	find_player(t_game *game);
void	count_items(t_game *game);
void	put_exit_win(t_game *game);
void	create_window(t_game *game);
void	ft_bzero(void *s, size_t n);
void	put_background(t_game *game);
void	put_background1(t_game *game);
void	*ft_calloc(size_t count, size_t size);

char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	**read_map(char **argv);
char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(const char *s);

#endif
