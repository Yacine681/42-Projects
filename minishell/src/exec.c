/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:26:16 by yabed             #+#    #+#             */
/*   Updated: 2022/10/21 15:57:30 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	exec_point(char **tmp, char **env)
{
	pid_t	pid;
	char	**save;
	char	*str;
	int		i;
	int		status;

	i = -1;
	save = NULL;
	pid = fork();
	str = tmp[0];
	if (pid == 0)
	{
		while (str[++i])
			if (str[i] == '/')
				break ;
		save = ft_split(str, '/');
		if (execve(save[1], tmp, env))
			printf("%s : No such file or directory\n", tmp[0]);
	}
	waitpid(pid, &status, 0);
	dollar_point(status);
	wait(&pid);
	ft_free(save);
}

void	exec_path(char **tmp, char **env)
{
	char	*str;
	int		status;
	pid_t	pid;

	pid = fork();
	str = ft_strjoin("/bin/", tmp[0]);
	if (pid == 0)
	{
		if (execve(str, tmp, env))
		{
			str = ft_strjoin("/usr/bin/", tmp[0]);
			if (execve(str, tmp, env))
			{
				write(2, "minishell: command not found\n", 30);
				g_status_global = 127;
				free(str);
				exit(0);
			}
		}
		exit(0);
	}
	waitpid(pid, &status, 0);
	dollar_point(status);
	wait(&pid);
	free(str);
}

void	exec_slash(char **tmp, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(tmp[0], tmp, env))
			printf("%s : No such file or directory\n", tmp[0]);
	}
	waitpid(pid, &status, 0);
	dollar_point(status);
	wait(&pid);
}

void	ft_exec(char **tmp, char **env)
{
	if (ft_strncmp(tmp[0], "./", 2) == 0)
		exec_point(tmp, env);
	else if (ft_strchr(tmp[0], '/') != NULL)
		exec_slash(tmp, env);
	else
		exec_path(tmp, env);
}
