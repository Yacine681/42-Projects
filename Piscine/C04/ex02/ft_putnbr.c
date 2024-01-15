/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:47:45 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:58:27 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
		nb = -nb;
			ft_putchar('-');
		}
		if (nb < 10)
		{
			ft_putchar(nb + 48);
		}
		else
		{		
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}