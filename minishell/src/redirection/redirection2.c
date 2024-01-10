/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:40:14 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:36:14 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static	int	where_is(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "<", 10) == 0)
			return (i);
		i++;
	}
	return (0);
}

static	void	cat_left(char **tmp)
{
	char	**tab;
	int		nb;

	tab = malloc(sizeof(char) * 3);
	nb = count_tab(tmp) - 1;
	tab[0] = tmp[0];
	tab[1] = tmp[nb];
	tab[2] = NULL;
	ft_exec(tab, NULL);
	free(tab);
}

static	void	last_left(char **tmp, int nb)
{
	char	**tab;
	int		i;

	i = -1;
	tab = malloc(sizeof(char) * 2);
	while (++i < nb)
		tab[i] = tmp[i];
	if (access(tmp[i + 1], F_OK))
	{
		printf("cd: no such file or directory: %s\n", tmp[2]);
		free(tab);
		return ;
	}
	tab[i] = NULL;
	ft_exec(tab, NULL);
	free(tab);
}

void	ft_redirection_2(char **tmp, char **env, char *str)
{
	int	nb;

	(void)str;
	(void)env;
	nb = where_is(tmp);
	if ((ft_strncmp(tmp[1], "<", 10) == 0)
		&& (ft_strncmp(tmp[0], "cat", 10) == 0))
		cat_left(tmp);
	else if (ft_strncmp(tmp[nb], "<", 10) == 0)
		last_left(tmp, nb);
}
