/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:52:21 by yabed             #+#    #+#             */
/*   Updated: 2022/04/08 15:44:31 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	return (nb);
}

unsigned int	ft_unsigned(unsigned int nb)
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
	ft_putnbr_unsigned(nb);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
