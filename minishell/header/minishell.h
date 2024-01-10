/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:08:37 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:37:57 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MINISHELL_LOGO "\
\e[0;38m+=====================================================================+\e[m\n\
\e[0;38m|\e[m\e[1;34m                                                                     \e[m\e[0;38m|\e[m\n\
\e[0;38m|\e[m\e[1;34m ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗      \e[m\e[0;38m|\e[m\n\
\e[0;38m|\e[m\e[1;36m ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║      \e[m\e[0;38m|\e[m\n\
\e[0;38m|\e[m\e[1;36m ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║      \e[m\e[0;38m|\e[m\n\
\e[0;38m|\e[m\e[1;36m ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║      \e[m\e[0;38m|\e[m\n\
\e[0;38m|\e[m\e[1;34m ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗ \e[m\e[0;38m|\e[m\n\
\e[0;38m|\e[m\e[1;34m ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ \e[m\e[0;38m|\e[m\n\
\e[0;38m+===================================\
==================================+\e[m\n\n"

# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/dir.h>
# include <getopt.h>
# include <signal.h>
# include <assert.h>
# include "libft.h"

pid_t	g_status_global;

typedef struct s_shell_utils
{
	int		i;
	int		a;
	char	**tmp;
	char	**split;
	int		taille;
	int		b;
	int		c;
	int		x;
}	t_utils;

void	pwd(char **tmp);
void	ft_signal(void);
void	cd(char **str);
void	ft_env(char **str);
void	ft_free(char **tmp);
void	dollar_point(int status);
void	ft_free_getenv(char **str);
void	ft_exit(char **tmp, char **env);
void	export(char **str, char **env);
void	ft_exec(char **tmp, char **env);
void	line_cmd(char *str, char **env);
void	ft_unset(char **str, char **env);
void	exec_slash(char **tmp, char **env);
void	echo_dollar_point(pid_t pid, int flag);
void	ft_pipe(char **str, char **env, char *tmp);
void	ft_single(char *str, char **av, char **env);
void	ft_echo(char **str, char **find, char *line);
void	create_pipe(char **tmp, char **argv, char **env);
void	ft_redirection(char **tmp, char **env, char *str);
void	ft_redirection_1(char **tmp, char **env, char *str);
void	ft_redirection_2(char **tmp, char **env, char *str);
void	ft_redirection_3(char **tmp, char **env, char *str);
void	ft_redirection_4(char **tmp, char **env, char *str);
void	cmd(char *str, char **env, char *line, char **pipe);

char	*supquote(char *str);
char	*bultin_1(char *str);
char	**init_tmp(char **tmp);
char	**echo_parsing(char *str);
char	*ft_getenv(char **str, char *find);

int		count(char **str);
int		count_tab(char **str);
int		count_pipe(char *str);
int		check_quote(char *str);
int		check_string(char *str);
int		check_number(char *str);
int		double_quotes(char *str);
int		single_quotes(char *str);
int		double_quotes(char *str);
int		what_quote(char *str, int nb);

#endif
