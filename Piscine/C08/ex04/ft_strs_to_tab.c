/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:25:12 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 14:56:55 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

char	*ft_strcpy(char *str, int size)
{
	int				a;
	char			*stock;

	stock = NULL;
	stock = malloc(sizeof(char) * (size + 1));
	a = 0;
	while (str[a])
	{
		stock[a] = str[a];
		a++;
	}
		stock[a] = 0;
	return (stock);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				a;
	t_stock_str		*stock;	

	a = 0;
	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	while (a < ac)
	{
		stock[a].size = ft_strlen(av[a]);
		stock[a].str = av[a];
		stock[a].copy = ft_strcpy(av[a], stock[a].size);
		a++;
	}
	stock[a].size = 0;
	stock[a].str = 0;
	stock[a].copy = 0;
	return (stock);
}