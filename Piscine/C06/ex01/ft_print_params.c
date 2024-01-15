/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:15:55 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 13:09:15 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	write (1, str, a);
}

int	main(int argc, char **argv)
{
	int	a;

	a = 1;
	(void) argc;
	while (argv[a])
	{
		ft_putstr(argv[a]);
		write(1, "\n", 1);
		a++;
	}
	return (0);
}