/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:42:24 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:39:30 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv_char(int c, t_opts opts)
{
	int	len;

	len = 1;
	while (opts.wdt > 1 && !opts.flags.minus)
	{
		ft_putchar(' ');
		opts.wdt--;
		len++;
	}
	ft_putchar(c);
	while (opts.wdt > 1 && opts.flags.minus)
	{
		ft_putchar(' ');
		opts.wdt--;
		len++;
	}
	return (len);
}
