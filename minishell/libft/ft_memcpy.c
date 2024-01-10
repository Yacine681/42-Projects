/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:48:48 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:41:54 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	if (!dst && !src)
		return (0);
	a = 0;
	while (a < n)
	{
		((char *)dst)[a] = ((char *)src)[a];
		a++;
	}
	return (dst);
}
