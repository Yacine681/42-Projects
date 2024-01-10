/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:04:49 by yabed             #+#    #+#             */
/*   Updated: 2022/10/19 15:14:30 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	pwd(char **tmp)
{
	char	*pwd;

	if (tmp[1])
	{
		printf("pwd: too many arguments\n");
		return ;
	}
	pwd = getcwd(0, 10000);
	printf("%s\n", pwd);
	g_status_global = 0;
	free(pwd);
}
