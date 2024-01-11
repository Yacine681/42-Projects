/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:11:18 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:55:24 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "structs.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>  
// #define MINI_SCALE 0.20
// #define TILE_SIZE 30
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
/*************** MLX ******************/
void	cub_3d(t_parma *ptr_mlx, t_map *parma);
int		mini_map(t_parma *maps);
/*************** INIT_STRUCT ******************/
void	init_color(t_color *color);
void	init_map(t_map *map);
void	init_game(t_parma *game);
void	start_game(t_parma *game);
/*************** utils ******************/
void	exit_error(char *msg, int code);
void	free_all(t_map *parma);
void	free_split(char **tab);
/*************** PARS ******************/
		/******pars******/	
void	get_data(t_parma *parma);
void	get_map_path(char *argv, t_parma *parma);
void	ft_get_map(t_parma *parma);
void	find_player(t_parma *parma);
		/******pars_utils******/
int		ft_set_char(char car, char *str);
int		num_ligne_of_map(char *path);
int		ft_map_len(t_parma *parma);
		/******check_map******/
int		ft_check_esp(char **map, int ligne, int colone);
int		check_maps(char **map);
int		check_map_2(t_parma *map, int ligne, int colone);
int		check_all_map(t_parma *parma);
		/******check_map_utils******/
int		ft_check_borde(char **map, int ligne, int index);
int		ft_check_borde2(char **map, int ligne, int index);
int		chech_all_wall_closed(char **map, int ligne);
void	check_map_content(t_parma *parma);
int		check_new_line(char *str);
		/******get_path_tex******/
void	get_path_texture(t_parma *parma);
void	get_path_color(t_parma *parma);
void	get_player_pos(t_map *map);

/*************** raycasting_tste ******************/
		/******move******/
int		release(int key, t_parma *ptr);
int		press(int key, t_parma*ptr);
void	move(t_parma *ptr);
void	rotate(t_parma *ptr, double angle);
void	left(t_parma *ptr);
void	right(t_parma *ptr);
void	backword(t_parma *ptr);
void	forword(t_parma *ptr);
int		start_scane(void *ptr);
void	ft_new_window(t_parma *game);
int		ft_close(t_parma *game);
/*******************************************************/
void	ray_draw(t_parma *wall);
void	ft_camera_3d(t_parma *cam);
void	ray_casting(t_parma *ray);
void	distance_cal(t_parma *d);
int		encode_rgb(t_color color);
void	ft_cei_floor(t_parma *star);
void	get_texture(t_parma *parm);
void	texture_wall(t_parma *parm);
void	put_texture(t_parma *parm);
void	start_drw(t_parma *parm);
int		start_scane(void *ptr);

#endif
