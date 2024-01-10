/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:22:26 by yabed             #+#    #+#             */
/*   Updated: 2022/03/29 08:45:23 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_ptr(unsigned long long x)
{
	char	*hexa;
	int		i;
	int		res[100];

	hexa = "0123456789abcdef";
	i = 0;
	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
	return (res[i]);
}

int	ft_print_ptr(unsigned long long nb)
{
	int	i;
	int	print;

	print = 0;
	if (nb)
	{
		print += write(1, "0x", 2);
		ft_putnbr_ptr(nb);
		i = 0;
		while (nb)
		{
			nb /= 16;
			i++;
		}
		print += i;
		return (print);
	}
	else
	{
		print += write(1, "0x0", 3);
		return (print);
	}
	return (0);
}
