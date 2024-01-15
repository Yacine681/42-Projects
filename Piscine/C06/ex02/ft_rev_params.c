/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:34:07 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 13:09:20 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char	*str)
{
	int	a;

	a = 0;
	while (str[a])
	a++;
	write (1, str, a);
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	while (argc > 1)
	{
		ft_putstr(argv[--argc]);
	}
	return (0);
}