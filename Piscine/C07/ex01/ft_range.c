/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:33:41 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 13:09:55 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	a;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	a = 0;
	while (min < max)
	{
		tab[a] = min;
		a++;
		min ++;
	}
	return (tab);
}