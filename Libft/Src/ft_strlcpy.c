/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:05:27 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:20 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != 0 && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
		dst[i] = '\0';
	return (ft_strlen(src));
}
