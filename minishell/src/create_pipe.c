/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:24:12 by yabed             #+#    #+#             */
/*   Updated: 2022/10/21 15:01:38 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static	void	exec_pipe(char *str, char **env, char *tmps)
{
	char	**tmp;

	tmp = echo_parsing(str);
	if (count(tmp) == 1)
	{
		ft_redirection(tmp, env, tmps);
		return ;
	}
	str = ft_strjoin("/bin/", tmp[0]);
	if (execve(str, tmp, env))
	{
		str = ft_strjoin("/usr/bin/", tmp[0]);
		if (ft_strchr(tmp[0], '/') != NULL)
			exec_slash(tmp, env);
		else if (execve(str, tmp, env))
			printf("can't find the command\n");
	}
	free(str);
}

static void	close_pipe(int *fd, int i)
{
	(void) i;
	close(fd[0]);
	close(fd[1]);
}

static	void	ft_wait_pid(char *line, int fd, pid_t pid)
{
	int	i;
	int	status;

	i = 0;
	close(fd);
	i = count_pipe(line);
	while (i > 0)
	{
		waitpid(pid, &status, 0);
		wait(NULL);
		i--;
	}
	dollar_point(status);
}

static	void	exec_child(int fd_in, int *fd, char **str, int i)
{
	dup2(fd_in, STDIN_FILENO);
	if (str[i + 1] != NULL)
		dup2(fd[1], STDOUT_FILENO);
	close(fd_in);
	close_pipe(fd, 1);
}

void	ft_pipe(char **str, char **env, char *tmp)
{
	int		fd_in;
	int		fd[2];
	pid_t	pid;
	int		i;

	fd_in = dup(STDIN_FILENO);
	i = 0;
	while (str[i])
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			exec_child(fd_in, fd, str, i);
			exec_pipe(str[i], env, tmp);
			exit(0);
		}
		else
		{
			dup2(fd[0], fd_in);
			close_pipe(fd, i++);
		}
	}
	ft_wait_pid(tmp, fd_in, pid);
	ft_free(str);
}
