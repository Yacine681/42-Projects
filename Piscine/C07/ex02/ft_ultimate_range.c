/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:51:36 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 13:10:07 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	a;

	if (min >= max)
	{	
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * (max - min));
	a = 0;
	while (min < max)
	{
		tab[a] = min;
		a++;
		min++;
	}
		*range = tab;
	return (a);
}