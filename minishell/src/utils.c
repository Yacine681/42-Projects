/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:57:31 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:53:42 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*ft_getenv(char **str, char *find)
{
	char	**tmp;
	char	*tmp1;
	int		a;

	a = 0;
	tmp1 = NULL;
	while (str[a])
	{
		tmp = ft_split(str[a], '=');
		if (ft_strncmp(tmp[0], find, 10000) == 0)
		{	
			tmp1 = tmp[1];
			ft_free_getenv(tmp);
			return (tmp1);
		}
		if (str[a + 1])
			ft_free(tmp);
		a++;
	}
	free(tmp);
	return (NULL);
}

int	count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], ">", 10) == 0 || ft_strncmp(str[i], "<", 10) == 0
			|| ft_strncmp(str[i], ">>", 10) == 0
			|| ft_strncmp(str[i], "<<", 10) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
	{
		if (str[i] >= 48 && str[i] <= 57)
			return (0);
		i++;
	}
	return (1);
}

int	count_pipe(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '|')
			nb++;
		i++;
	}
	return (nb);
}

int	check_string(char *str)
{
	int		i;
	char	**tmp;

	tmp = ft_split(str, ' ');
	i = 0;
	while (tmp[i])
	{
		if (check_quote(tmp[i]) == 1)
		{
			ft_free(tmp);
			return (1);
		}
		i++;
	}
	ft_free(tmp);
	return (0);
}
