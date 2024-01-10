/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:34:22 by yabed             #+#    #+#             */
/*   Updated: 2022/10/14 11:22:26 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_getenv(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		if (i != 1)
			free(str[i]);
		i++;
	}
	free(str);
}
