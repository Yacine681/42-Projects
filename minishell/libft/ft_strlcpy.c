/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:24:39 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:42:55 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;

	if (size == 0)
		return (ft_strlen(src));
	a = 0;
	while (src[a] && a < size - 1)
	{
		dst[a] = src[a];
		a++;
	}
	if (a < size + 1)
		dst[a] = '\0';
	return (ft_strlen(src));
}
