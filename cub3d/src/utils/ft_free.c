/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:27:14 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:31:58 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	exit_error(char *msg, int code)
{
	ft_putstr_fd(msg, code);
	exit(code);
}

void	free_all(t_map *parma)
{
	int	i;

	i = -1;
	while (parma->map[++i])
	{
		free(parma->map[i]);
	}
	free(parma->map);
}

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
