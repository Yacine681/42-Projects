/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:52:29 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 15:01:20 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static	void	new_prompt(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static	void	message_quit(int signum)
{
	if (signum == SIGSEGV)
	{
		printf("GoodBye :)\n");
		exit(0);
	}
}

void	ft_signal(void)
{
	signal(SIGSEGV, message_quit);
	signal(SIGINT, new_prompt);
	signal(SIGQUIT, SIG_IGN);
}
