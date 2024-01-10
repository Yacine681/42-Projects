/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:26:10 by yabed             #+#    #+#             */
/*   Updated: 2022/10/21 16:30:20 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_n(char **str)
{
	int		i;

	i = 1;
	while (ft_strncmp(str[i], "-n", 10) == 0)
		i++;
	return (i - 1);
}

int	what_quote(char *str, int nb)
{
	int	i;
	int	d;
	int	w;

	i = 0;
	d = 1;
	while (str[i])
	{
		if (str[i] == '$' && d == nb)
			w = i;
		if (str[i] == '$')
			d++;
		i++;
	}
	if (d > 0)
	{
		while (str[w++])
		{
			if (str[w] == 39)
				return (0);
			if (str[w] == '"')
				break ;
		}
	}
	return (1);
}

int	check_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((str[i] == '"' && str[i + 1] == '"')
				|| (str[i] == '"' && ft_isalpha(str[i - 1]) == 1))
			&& (ft_isalpha(str[i + 1]) == 1 && str[i + 1] != ' '))
			return (1);
		i++;
	}
	return (0);
}

int	reduce_echo(char **str, int i, char **find, char *line)
{
	char	*env;
	char	**tmp;
	int		indent;

	indent = 0;
	tmp = ft_split(str[i], '$');
	env = ft_getenv(find, tmp[0]);
	free(tmp);
	if (env)
	{
		if (check_string(line) == 1)
			printf("%s", env);
		else if (check_string(line) == 0)
			printf("%s ", env);
		indent++;
	}
	return (indent);
}

void	ft_echo(char **str, char **find, char *line)
{
	int	i;
	int	indent;
	int	quote;

	if (ft_strncmp(str[1], "-n", 100) == 0 && !str[2])
	{
		printf("\n");
		return ;
	}
	quote = 1;
	i = check_n(str);
	while (str[++i])
	{
		indent = 0;
		quote = 1;
		if (str[i][0] == '$' && what_quote(line, quote))
			indent = reduce_echo(str, i, find, line);
		if (indent == 0 && str[i][0] != 39 && check_string(line) == 0)
			printf("%s ", str[i]);
		else if (indent == 0 && str[i][0] != 39 && check_string(line) == 1)
			printf("%s", str[i]);
	}
	if (ft_strncmp(str[1], "-n", 10))
		printf("\n");
}
