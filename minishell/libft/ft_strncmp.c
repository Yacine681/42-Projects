/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:26:14 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:43:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while ((s1[a] && s2[a]) && (s1[a] == s2[a]) && (a + 1 < n))
		a++;
	return (((unsigned char *)s1)[a] - ((unsigned char *)s2)[a]);
}
