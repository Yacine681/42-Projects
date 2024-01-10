/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:05:07 by yabed             #+#    #+#             */
/*   Updated: 2022/10/20 11:24:06 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	dollar_point(int pid)
{
	if (WIFEXITED(pid))
		g_status_global = WEXITSTATUS(pid);
	else if (WIFSIGNALED(pid))
		g_status_global = WTERMSIG(pid);
}

void	echo_dollar_point(pid_t status_global, int flag)
{
	if (flag == 1)
		printf("%d: command not found\n", status_global);
	else
		printf("%d\n", status_global);
}
