/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:55:51 by yabed             #+#    #+#             */
/*   Updated: 2022/04/06 15:07:55 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_print_hexa(unsigned int x)
{
	char	*hexa;
	int		i;
	int		res[100];

	hexa = "0123456789ABCDEF";
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

int	ft_print_hexa_maj(unsigned int nb)
{
	int	i;
	int	len;

	len = 0;
	if (nb == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	i = 0;
	ft_print_hexa(nb);
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}
