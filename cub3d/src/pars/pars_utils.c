/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:40:40 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:33:45 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_set_char(char car, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (car == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	num_ligne_of_map(char *path)
{
	int		i;
	int		fd;
	char	*ligne;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error("File Descriptor Failure\n", 1);
	ligne = get_next_line(fd);
	while (ligne)
	{
		free(ligne);
		i++;
		ligne = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	ft_map_len(t_parma *parma)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (parma->cub_content[i])
	{
		if (parma->cub_content[i][0] == '1'
			|| parma->cub_content[i][0] == '0'
			|| parma->cub_content[i][0] == ' ')
			len++;
		i++;
	}
	return (len);
}

int	check_new_line(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}
