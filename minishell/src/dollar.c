/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:34:27 by yabed             #+#    #+#             */
/*   Updated: 2022/10/20 16:25:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*str_dollar(char *str, char **env)
{
	int		i;
	int		a;
	char	*tmp;

	tmp = malloc(sizeof(char) * 100000);
	i = 0;
	a = 0;
	while (str[i] != '$')
		i++;
	i++;
	while (str[i])
	{
		tmp[a] = str[i];
		i++;
		a++;
	}
	tmp[a] = '\0';
	return (ft_getenv(env, tmp));
}
