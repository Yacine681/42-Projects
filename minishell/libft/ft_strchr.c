/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:04:52 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:42:32 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;

	a = 0;
	while (s[a])
	{
		if (s[a] == c)
			return (((char *)s) + a);
		a++;
	}
	if (s[a] == c)
		return (((char *)s) + a);
	return (NULL);
}
