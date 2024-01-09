/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:49:42 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:37 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
		i++;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
