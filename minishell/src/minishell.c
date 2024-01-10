/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:26:28 by yabed             #+#    #+#             */
/*   Updated: 2022/10/21 16:02:41 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	main(int ac, char *av[], char *env[])
{
	char	*command;

	(void)ac;
	(void)av;
	printf("%s", MINISHELL_LOGO);
	printf("MINISHELL 42 BY yabed && joberle\n\n");
	printf("Welcome %s!", getenv("USER"));
	printf("\n\n");
	ft_signal();
	while (1)
	{
		command = readline("\033[1;32m→ @MiniShell ~ $> \001\e[0m\002");
		add_history(command);
		if (*command)
			line_cmd(command, env);
		free(command);
	}
}
