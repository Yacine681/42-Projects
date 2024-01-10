/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:25:52 by yabed             #+#    #+#             */
/*   Updated: 2022/10/19 15:15:47 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	cd(char **str)
{
	char	*racine;

	racine = getenv("HOME");
	if (str[1] == NULL)
		chdir(racine);
	else if (chdir(str[1]) == -1)
		printf("cd: no such file or directory: %s\n", str[1]);
	g_status_global = 0;
}
