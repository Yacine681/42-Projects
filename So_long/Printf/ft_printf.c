/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 08:16:23 by yabed             #+#    #+#             */
/*   Updated: 2022/04/08 15:07:39 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_formats(va_list ap, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_charactere(va_arg(ap, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (format == 'd')
		print_len += ft_nbr(va_arg(ap, int));
	else if (format == 'i')
		print_len += ft_nbr(va_arg(ap, int));
	else if (format == 'u')
		print_len += ft_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x')
		print_len += ft_print_hexa_min(va_arg(ap, unsigned int));
	else if (format == 'X')
		print_len += ft_print_hexa_maj(va_arg(ap, unsigned int));
	else if (format == '%')
		print_len += ft_print_pourcent();
	return (print_len);
}

int	ft_printf(const char *print, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, print);
	if (print == NULL)
		return (write(1, "(null)", 6));
	while (print[i])
	{
		if (print[i] == '%')
		{
			len += ft_search_formats(ap, print[i + 1]);
			i++;
		}
		else
			len += write(1, &print[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
