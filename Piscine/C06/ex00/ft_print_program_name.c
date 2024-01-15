/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:30:00 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 13:03:04 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		ft_putchar(str[a]);
		a++;
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	ft_putstr(argv[0]);
	ft_putchar('\n');
	return (0);
}