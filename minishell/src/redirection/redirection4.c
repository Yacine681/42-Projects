/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:41:18 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:59:46 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static	int	where_is(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "<<", 10) == 0)
			return (i);
		i++;
	}
	return (0);
}

void	redir_cat(char **tmp)
{
	char	*buffer;
	char	*str;

	if (ft_strncmp(tmp[1], "<<", 10) == 0)
	{
		str = malloc(sizeof(char) * 1000000);
		buffer = malloc(sizeof(char) * 1000000);
		while (ft_strncmp(str, tmp[2], 10000))
		{
			str = readline("heredoc> ");
			if (ft_strncmp(str, tmp[2], 10000))
			{
				buffer = ft_strjoin(buffer, str);
				buffer = ft_strjoin(buffer, "\n");
			}
			free(str);
		}
		write(1, buffer, ft_strlen(buffer));
		free(buffer);
	}
}

void	other_redir_1(char **tmp)
{
	char	**tab;
	char	*buffer;
	char	*str;


	tab = tmp;
	if (ft_strncmp(tmp[1], "<<", 10) == 0)
	{
		str = malloc(sizeof(char) * 1000000);
		buffer = malloc(sizeof(char) * 1000000);
		while (ft_strncmp(str, tmp[2], 10000))
		{
			str = readline("heredoc> ");
			if (ft_strncmp(str, tmp[2], 10000))
			{
				buffer = ft_strjoin(buffer, str);
				buffer = ft_strjoin(buffer, "\n");
			}
			free(str);
		}
		tab[1] = NULL;
		ft_exec(tab, NULL);
		free(buffer);
	}
}

void	other_redir_2(char **tmp, int nb)
{
	char	*buffer;
	char	*str;
	char	**tab;

	tab = tmp;
	if (ft_strncmp(tmp[nb], "<<", 10) == 0)
	{
		str = malloc(sizeof(char) * 1000000);
		buffer = malloc(sizeof(char) * 1000000);
		while (ft_strncmp(str, tmp[nb + 1], 10000))
		{
			str = readline("heredoc> ");
			if (ft_strncmp(str, tmp[nb + 1], 10000))
			{
				buffer = ft_strjoin(buffer, str);
				buffer = ft_strjoin(buffer, "\n");
			}
			free(str);
		}
		tab[nb] = NULL;
		ft_exec(tab, NULL);
		free(buffer);
	}
}

void	ft_redirection_4(char **tmp, char **env, char *str)
{
	int	nb;

	(void)str;
	(void)env;
	nb = where_is(tmp);
	if ((ft_strncmp(tmp[0], "cat", 10) == 0)
		&& (ft_strncmp(tmp[1], "<<", 10) == 0))
		redir_cat(tmp);
	else if (ft_strncmp(tmp[1], "<<", 10) == 0)
		other_redir_1(tmp);
	else if (nb > 1)
		other_redir_2(tmp, nb);
}
