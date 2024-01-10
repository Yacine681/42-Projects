/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:57:31 by yabed             #+#    #+#             */
/*   Updated: 2022/10/18 13:18:40 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	**init_tmp(char **tmp)
{
	int	a;

	a = 0;
	tmp = malloc (sizeof(char *) * 1000);
	while (a < 1000)
	{
		tmp[a] = NULL;
		++a;
	}
	return (tmp);
}
