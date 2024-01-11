/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 05:22:28 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:34:04 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_data(t_parma *parma)
{
	int	len;
	int	i;
	int	fd;

	i = 0;
	len = num_ligne_of_map(parma->map.filename);
	parma->cub_content = malloc(sizeof(char *) * (len + 1));
	if (!parma->cub_content)
		exit_error("Malloc Failure\n", 1);
	fd = open(parma->map.filename, O_RDONLY);
	if (fd == -1)
		exit_error("File Descriptor Failure\n", 1);
	parma->cub_content[i] = get_next_line(fd);
	while (i < len && parma->cub_content[i++])
		parma->cub_content[i] = get_next_line(fd);
	parma->cub_content[i] = 0;
	close(fd);
}

void	ft_get_map(t_parma *parma)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	parma->map.line = ft_map_len(parma);
	parma->map.map = malloc(sizeof(char *) * (parma->map.line + 1));
	parma->map.colonne = 0;
	if (!parma->map.map)
		exit_error("Malloc Failure\n", 1);
	while (parma->cub_content[i])
	{
		if (parma->cub_content[i][0] == '1'
			|| parma->cub_content[i][0] == ' '
			|| parma->cub_content[i][0] == '0')
		{
			parma->map.map[k++] = ft_strndup(parma->cub_content[i],
					ft_strlen(parma->cub_content[i]) - \
					check_new_line(parma->cub_content[i]));
			if (parma->map.colonne < ft_strlen(parma->map.map[k - 1]))
				parma->map.colonne = ft_strlen(parma->map.map[k - 1]);
		}
		i++;
	}
	parma->map.map[k] = NULL;
}

void	get_map_path(char *argv, t_parma *parma)
{
	parma->map.filename = ft_strdup(argv);
	get_data(parma);
	check_map_content(parma);
	get_path_texture(parma);
	get_path_color(parma);
	ft_get_map(parma);
	get_player_pos(&parma->map);
	check_maps(parma->map.map);
	check_all_map(parma);
}
