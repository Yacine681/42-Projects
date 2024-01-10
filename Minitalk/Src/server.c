/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:47:06 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 12:37:26 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minitalk.h"

void	signal_handler(int signum)
{
	static unsigned char	buffer = 0;
	static int				counter = 128;
	static int				i = 8;

	if (signum == SIGUSR1)
	{
		buffer += counter;
		counter = counter / 2;
	}
	else if (signum == SIGUSR2)
		counter = counter / 2;
	i--;
	if (i <= 0 || counter < 1)
	{
		write(1, &buffer, 1);
		i = 8;
		counter = 128;
		buffer = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "Server launched, PID = ", 22);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
