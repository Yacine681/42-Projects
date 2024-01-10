/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:26:22 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:53:14 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	count_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	check_egale(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

static	int	check_double(char *str, char **env)
{
	char	**tmp1;
	char	**tmp2;
	int		i;

	i = 0;
	tmp2 = ft_split(str, '=');
	while (env[i])
	{
		tmp1 = ft_split(env[i], '=');
		if (ft_strncmp(tmp1[0], tmp2[0], 10) == 0)
		{
			env[i] = ft_strdup(str);
			ft_free(tmp1);
			ft_free(tmp2);
			return (1);
		}
		if (env[i + 1])
			ft_free(tmp1);
		i++;
	}
	ft_free(tmp1);
	ft_free(tmp2);
	return (0);
}

static	char	**concatene(char **str)
{
	t_utils	i;

	i.i = 0;
	i.a = 0;
	i.tmp = init_tmp(i.tmp);
	i.tmp[i.a] = str[0];
	i.a++;
	while (str[++i.i])
	{
		if (((check_egale(str[i.i]) == 1 && str[i.i + 1] == NULL))
			|| (check_egale(str[i.i]) == 0 && check_egale(str[i.i]) == 1))
			i.tmp[i.a] = str[i.i];
		else if ((ft_strncmp(str[i.i + 1], "=", 10) == 0)
			&& check_egale(str[i.i]) == 0)
			return (NULL);
		else if (check_egale(str[i.i]) == 1 && check_egale(str[i.i + 1]) == 0)
		{
			i.tmp[i.a] = ft_strjoin(str[i.i], str[i.i + 1]);
			i.i++;
		}
		else
			i.tmp[i.a] = str[i.i];
		i.a++;
	}
	return (i.tmp);
}

void	export(char **str, char **env)
{
	char	*tmp;
	int		a;
	int		i;

	a = count_tab(env) - 1;
	tmp = env[a];
	i = 0;
	str = concatene(str);
	if (str == NULL)
		return ;
	while (str[++i] != NULL)
	{
		if (check_egale(str[i]) == 0 || check_number(str[i]) == 0)
			return ;
		if (check_double(str[i], env) == 0)
		{
			env[a] = ft_strdup(str[i]);
			a++;
		}
	}
	env[a++] = tmp;
	env[a] = (void *) '\0';
	free(str);
	g_status_global = 0;
}
