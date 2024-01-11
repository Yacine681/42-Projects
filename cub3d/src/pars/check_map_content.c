/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:23:31 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:32:48 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map_parma_content(t_parma *parma, int *i)
{
	int		find;

	find = 0;
	while (*i < 4 && parma->cub_content[*i])
	{
		if (ft_strncmp(parma->cub_content[*i], "NO ", 3) == 0 \
			|| ft_strncmp(parma->cub_content[*i], "SO ", 3) == 0 \
			|| ft_strncmp(parma->cub_content[*i], "WE ", 3) == 0 \
			|| ft_strncmp(parma->cub_content[*i], "EA ", 3) == 0 \
			)
		{		
			find++;
		}
		(*i)++;
	}
	if (*i != find && find != 4)
		exit_error("Invalid Texture\n", 1);
	if (*i == 0)
		exit_error("Invalid File: Empty Texture", 1);
}

void	check_map_color(char **color, int *i)
{
	int		find;
	int		ii;
	int		k;

	find = 0;
	k = *i;
	ii = *i + 2;
	while (*i < ii && color[*i])
	{
		if (ft_strncmp(color[*i], "F ", 2) == 0 \
			|| ft_strncmp(color[*i], "C ", 2) == 0)
			find++;
		(*i)++;
	}
	if (*i - k != find)
		exit_error("Invalid Color\n", 1);
}

void	check_map_content(t_parma *parma)
{
	int	i;

	i = 0;
	check_map_parma_content(parma, &i);
	while (parma->cub_content[i] && ft_strcmp(parma->cub_content[i], "\n") == 0)
		i++;
	check_map_color(parma->cub_content, &i);
	while (parma->cub_content[i] && ft_strcmp(parma->cub_content[i], "\n") == 0)
		i++;
}
