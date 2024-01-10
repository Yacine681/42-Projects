/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:25:58 by yabed             #+#    #+#             */
/*   Updated: 2022/10/21 15:47:01 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static	int	check_single_quotes(char *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[0] == 39 || str[0] == 34)
		{
			while (str[a])
			{
				if (str[a] == '|' || str[a] == '<' || str[a] == '>')
				{
					printf("command not found\n");
					g_status_global = 127;
					return (1);
				}
				a++;
			}
		}
		i++;
	}
	return (0);
}

void	line_cmd(char *str, char **env)
{
	char	**pipe;
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return ;
	if (check_single_quotes(str) == 1)
		return ;
	if (!(double_quotes(str) % 2 == 0) || !(single_quotes(str) % 2 == 0))
		return ;
	pipe = ft_split(str, '|');
	if (pipe[1] && double_quotes(pipe[0]) == 0
		&& double_quotes(pipe[1]) == 0)
		ft_pipe(pipe, env, str);
	else
		cmd(str, env, str, pipe);
}

static	int	raccourci(char **env, char *line, char **tmp)
{
	if (count(tmp) == 1)
		ft_redirection(tmp, env, line);
	else if ((ft_strncmp(tmp[0], "echo", 10) == 0)
		&& ft_strncmp(tmp[1], "$?", 10) == 0)
		echo_dollar_point(g_status_global, 0);
	else if (ft_strncmp(tmp[0], "echo", 10) == 0)
		ft_echo(tmp, env, line);
	else if (ft_strncmp(tmp[0], "pwd", 10) == 0)
		pwd(tmp);
	else if (ft_strncmp(tmp[0], "env", 10) == 0)
		ft_env(env);
	else if (ft_strncmp(tmp[0], "export", 10) == 0)
		export(tmp, env);
	else if (ft_strncmp(tmp[0], "cd", 10) == 0)
		cd(tmp);
	else if (ft_strncmp(tmp[0], "unset", 10) == 0)
		ft_unset(tmp, env);
	else if (ft_strncmp(tmp[0], "exit", 10) == 0)
		ft_exit(tmp, env);
	else
		return (0);
	return (1);
}

void	cmd(char *str, char **env, char *line, char **pipe)
{
	char	**tmp;

	if (ft_strncmp(str, "$? + $?", 10) == 0)
	{
		echo_dollar_point(g_status_global, 1);
		ft_free(pipe);
		return ;
	}
	tmp = echo_parsing(str);
	if (ft_strncmp(tmp[0], "echo", 10) == 0 && !tmp[1])
	{
		printf("\n");
		return ;
	}
	ft_free(pipe);
	if (tmp == NULL)
		return ;
	if (raccourci(env, line, tmp) == 0)
		ft_exec(tmp, env);
	ft_free(tmp);
}
