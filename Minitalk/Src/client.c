/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:44:48 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:38:16 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minitalk.h"

void	send_char(char a, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (a & (128 >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (i < ft_strlen(argv[2]))
		{
			send_char(argv[2][i], pid);
			i++;
		}
		send_char('\n', pid);
	}
	else
	{
		write(1, "Usage : ./client [PID] [String]\n", 45);
	}
}
