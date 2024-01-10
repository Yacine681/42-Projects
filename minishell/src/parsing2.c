/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:26:38 by yabed             #+#    #+#             */
/*   Updated: 2022/10/19 11:48:57 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	is_meta(char *str, int quote)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if ((str[i] >= 33 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64)
			|| (str[i] >= 91 && str[i] <= 96)
			|| (str[i] >= 123 && str[i] <= 126))
		a++;
		if ((str[i] == '$' && quote == 2) || str[i] == 61)
			a--;
		i++;
	}
	return (a);
}

int	ft_meta(char c, int quote)
{
	if ((c == '$' && quote == 2) || c == 61)
		return (0);
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64)
		|| (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		return (1);
	return (0);
}

char	*supquote(char *str)
{
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	tmp = ft_strdup(str);
	while (str[i])
	{
		if (!ft_meta(str[i], 2))
		{
			tmp[a] = str[i];
			a++;
		}
		i++;
	}
	tmp[a] = '\0';
	return (tmp);
}
