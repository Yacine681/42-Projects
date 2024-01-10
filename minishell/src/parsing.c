/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:26:33 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:53:59 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	if_quote(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == 39)
		{
			str[i++] = ' ';
			while (str[i] != '"' && str[i] != 39)
			{
				if (str[i] == ' ')
					str[i] = (char)666;
				i++;
			}
			if (str[i] == '"' || str[i] == 39)
				str[i] = ' ';
			nb = 2;
		}
		i++;
	}
	return (nb);
}

void	supp_quote(char **str)
{
	int	i;
	int	a;

	a = 0;
	while (str[a])
	{
		i = 0;
		while (str[a][i])
		{
			if (str[a][i] == (char)666)
				str[a][i] = ' ';
			i++;
		}
		a++;
	}
}

int	double_quotes(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '"')
			x++;
		i++;
	}
	return (x);
}

int	single_quotes(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == 39)
			x++;
		i++;
	}
	return (x);
}

char	**echo_parsing(char *str)
{
	char	**tmp;
	int		nb;

	if (!(double_quotes(str) % 2 == 0) || !(single_quotes(str) % 2 == 0))
		return (NULL);
	nb = if_quote(str);
	if (nb)
	{
		tmp = ft_split(str, ' ');
		supp_quote(tmp);
	}
	else
		tmp = ft_split(str, ' ');
	return (tmp);
}
