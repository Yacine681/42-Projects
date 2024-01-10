/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:24:03 by yabed             #+#    #+#             */
/*   Updated: 2022/10/25 10:23:38 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static	int	verif_digit(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '+' || tmp[i] == '-')
			i++;
		else if (ft_isdigit(tmp[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(char **tmp, char **env)
{
	(void)env;
	if (count_tab(tmp) > 2)
	{
		printf("exit\nexit: too many arguments\n");
		g_status_global = 1;
	}
	else if (tmp[1] && verif_digit(tmp[1]) == 0)
	{
		printf("exit\nbash: exit: %s: numeric argument required\n", tmp[1]);
		ft_free(tmp);
		exit(255);
	}
	else
	{
		printf("exit\n");
		if (tmp[1])
		{
			ft_free(tmp);
			exit(ft_atoi(tmp[1]));
		}
		ft_free(tmp);
		exit(0);
	}
}
