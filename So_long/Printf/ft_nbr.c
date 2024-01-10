/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:49:15 by yabed             #+#    #+#             */
/*   Updated: 2022/04/08 15:46:44 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(int nb)
{
	int	i;
	int	number;
	int	neg;

	i = 0;
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
	{
		neg = 0;
		number = nb;
	}
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i + neg);
}

int	ft_nbr(int nb)
{
	int		len;
	long	a;

	a = nb;
	len = 0;
	if (nb == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	if (a < 0)
	{
		ft_putchar('-');
		a = a * -1;
	}
	if (a < 10)
		ft_putchar(a + 48);
	else
	{
		ft_nbr(a / 10);
		ft_nbr(a % 10);
	}
	len += ft_len(nb);
	return (len);
}
