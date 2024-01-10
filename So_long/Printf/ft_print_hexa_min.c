/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:17:08 by yabed             #+#    #+#             */
/*   Updated: 2022/03/28 14:27:10 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_print_hexa1(unsigned int x)
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

int	ft_print_hexa_min(unsigned int nb)
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
	ft_print_hexa1(nb);
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}
