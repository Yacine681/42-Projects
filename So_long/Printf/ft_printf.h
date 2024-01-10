/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 08:19:24 by yabed             #+#    #+#             */
/*   Updated: 2022/03/30 11:32:22 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void			ft_putchar(char c);

int				ft_printf(const char *print, ...);
int				ft_print_hexa_maj(unsigned int nb);
int				ft_print_hexa_min(unsigned int nb);
int				ft_search_formats(va_list ap, const char format);
int				ft_print_ptr(unsigned long long nb);
int				ft_print_charactere(int c);
int				ft_print_pourcent(void);
int				ft_print_str(char *str);
int				ft_len(int nb);
int				ft_nbr(int nb);

unsigned int	ft_print_hexa(unsigned int x);
unsigned int	ft_print_hexa1(unsigned int x);
unsigned int	ft_putnbr_ptr(unsigned long long x);
unsigned int	ft_putnbr_unsigned(unsigned int nb);
unsigned int	ft_unsigned(unsigned int nb);
#endif
