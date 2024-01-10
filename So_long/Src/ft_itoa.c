/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:04:41 by yabed             #+#    #+#             */
/*   Updated: 2022/03/11 14:21:03 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

static unsigned int	ft_str(int n)
{
	unsigned int	str;

	str = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		str++;
	while (n)
	{
		n /= 10;
		str++;
	}
	return (str);
}

static	int	ft_neg(char *tab, unsigned int i, int n)
{
	if (n < 0)
	{
		tab[0] = '-';
		i = 1;
	}
	else
		i = 0;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	str;
	unsigned int	i;
	char			*tab;

	str = ft_str(n);
	tab = (char *)malloc(str + 1);
	if (!tab)
		return (NULL);
	tab[str] = '\0';
	i = 0;
	i = ft_neg(tab, i, n);
	while (str-- > i)
	{
		if (n < 0)
		{
			tab[str] = '0' + n % 10 * (-1);
			n = n / 10;
		}
		else
		{
			tab[str] = '0' + n % 10;
			n = n / 10;
		}
	}
	return (tab);
}
