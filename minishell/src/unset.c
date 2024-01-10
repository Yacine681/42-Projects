/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:26:50 by yabed             #+#    #+#             */
/*   Updated: 2022/10/21 16:10:10 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_unset(char **str, char **env)
{
	t_utils	i;

	i.b = -1;
	i.c = 1;
	while (env[++i.b] && str[i.c])
	{
		i.split = ft_split(env[i.b], '=');
		i.taille = ft_strlen(i.split[0]);
		i.x = ft_strlen(str[i.c]);
		if ((ft_strncmp(str[i.c], i.split[0], i.taille) == 0)
			&& (ft_strncmp(str[i.c], i.split[0], i.x) == 0))
		{
			if (str[i.c + 1])
				ft_free(i.split);
			i.c++;
			i.x = i.b - 1;
			while (env[++i.x])
				env[i.x] = env[i.x + 1];
			env[i.x + 1] = NULL;
			i.b = -1;
		}
		else
			ft_free(i.split);
	}
	ft_free(i.split);
}
