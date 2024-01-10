/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:30:09 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:43:11 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!s2[a])
		return ((char *)s1);
	while (s1[a] && a < len)
	{
		b = 0;
		while (s2[b] && s1[a + b] && s1[a + b] == s2[b]
			&& (a + b) < len)
			b++;
		if (!s2[b])
			return ((char *)s1 + a);
		a++;
	}
	return (NULL);
}
