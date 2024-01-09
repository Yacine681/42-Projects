/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:46:46 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:22 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total;
	size_t	original;

	original = size;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst && size > 0)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (ft_strlen(src) + original);
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = 0;
	return (total);
}
