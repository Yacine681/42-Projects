/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:39:52 by yabed             #+#    #+#             */
/*   Updated: 2022/10/21 10:46:04 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static	char	*bultin(char *str)
{
	char	**tmp;
	char	*tmp1;

	tmp = ft_split(str, '>');
	tmp1 = ft_strdup(tmp[0]);
	ft_free(tmp);
	return (tmp1);
}

void	static	ft_redirection_echo(char **tmp, char **env, char *str)
{
	pid_t	pid;
	int		ret;
	char	*tmp1;

	tmp1 = bultin(str);
	ret = open(tmp[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	pid = fork();
	if (pid == 0)
	{
		if (ret == -1)
		{
			free(tmp1);
			exit(EXIT_FAILURE);
		}
		close(1);
		dup2(ret, 1);
		cmd(tmp1, env, str, NULL);
		exit(0);
	}
	else
		wait(&pid);
	close(ret);
	free(tmp1);
}

void	static	ft_redirection_exec(char **tmp, char **env, char *str)
{
	pid_t	pid;
	int		ret;

	ret = open(tmp[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	pid = fork();
	if (pid == 0)
	{
		if (ret == -1)
			exit(EXIT_FAILURE);
		close(1);
		dup2(ret, 1);
		if (ft_strncmp(tmp[0], "echo", 10) == 0
			&& ft_strncmp(tmp[1], ">", 10) == 0)
			printf("\n");
		cmd(tmp[0], env, str, NULL);
		exit(0);
	}
	else
		wait(&pid);
	close(ret);
}

void	static	ft_redirection_echo_1(char **tmp)
{
	pid_t	pid;
	int		ret;

	ret = open(tmp[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	pid = fork();
	if (pid == 0)
	{
		if (ret == -1)
			exit(EXIT_FAILURE);
		close(1);
		dup2(ret, 1);
		exit(0);
	}
	else
		wait(&pid);
	close(ret);
}

void	ft_redirection_1(char **tmp, char **env, char *str)
{
	if ((ft_strncmp(tmp[0], ">", 10) == 0) && tmp[1])
		ft_redirection_echo_1(tmp);
	else if ((ft_strncmp(tmp[1], ">", 10) == 0) && tmp[2])
		ft_redirection_exec(tmp, env, str);
	else if ((ft_strncmp(tmp[2], ">", 10) == 0) && tmp[3])
		ft_redirection_echo(tmp, env, str);
}
