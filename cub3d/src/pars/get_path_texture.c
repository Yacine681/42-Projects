/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:26:33 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:33:31 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	open_texture(t_parma *tex)
{
	if (open(tex->map.north_texture, O_RDONLY) < 0 \
		|| open(tex->map.south_texture, O_RDONLY) < 0 \
		|| open(tex->map.east_texture, O_RDONLY) < 0 \
		|| open(tex->map.west_texture, O_RDONLY) < 0)
		exit_error("Texture : No Exist \n", 1);
}

void	get_path_texture(t_parma *parma)
{
	char	**path_tex;
	int		i;

	i = 0;
	while (i < 4)
	{
		path_tex = ft_split_str(parma->cub_content[i++], ", \n");
		if (!path_tex)
			return ;
		if (ft_strcmp(path_tex[0], "NO") == 0)
			parma->map.north_texture = ft_strdup(path_tex[1]);
		else if (ft_strcmp(path_tex[0], "SO") == 0)
			parma->map.south_texture = ft_strdup(path_tex[1]);
		else if (ft_strcmp(path_tex[0], "WE") == 0)
			parma->map.west_texture = ft_strdup(path_tex[1]);
		else if (ft_strcmp(path_tex[0], "EA") == 0)
			parma->map.east_texture = ft_strdup(path_tex[1]);
		free_split(path_tex);
	}
	open_texture(parma);
}

void	get_color_rgb(t_color *color, char **str)
{
	color->r = ft_atoi(str[0]);
	color->g = ft_atoi(str[1]);
	color->b = ft_atoi(str[2]);
}

void	get_path_color(t_parma *parma)
{
	char	**get_fc;
	int		i;

	i = 0;
	while (parma->cub_content[i])
	{
		get_fc = ft_split_str(parma->cub_content[i++], ", \n");
		if (!get_fc)
			return ;
		if (ft_strcmp(get_fc[0], "F") == 0)
			get_color_rgb(&parma->map.floor_color, get_fc + 1);
		else if (ft_strcmp(get_fc[0], "C") == 0)
			get_color_rgb(&parma->map.ceilling_color, get_fc + 1);
	}
}

void	get_player_pos(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (map->map[row])
	{
		col = 0;
		while (map->map[row][col])
		{
			if (ft_set_char(map->map[row][col], "NSEW"))
			{
				map->player.x = row;
				map->player.y = col;
				map->starting_pos = map->map[row][col];
				return ;
			}
			col++;
		}
		row++;
	}
}
