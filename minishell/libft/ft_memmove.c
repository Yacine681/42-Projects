/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:24:15 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:41:59 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;

	if (!dst && !src)
		return (0);
	a = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		a = len - 1;
		while (a < len)
		{
			((char *)dst)[a] = ((char *)src)[a];
			a--;
		}
	}
	else
	{
		while (a < len)
		{
			((char *)dst)[a] = ((char *)src)[a];
			a++;
		}
	}
	return (dst);
}
