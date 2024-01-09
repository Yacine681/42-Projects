/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:55:21 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:39 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*dest;
	const unsigned char		*source;

	i = 0;
	dest = dst;
	source = src;
	if (!dest && !source)
		return (0);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
