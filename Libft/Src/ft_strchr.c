/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:56:09 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:28 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)*s == (char)c)
			return ((char *)s);
			s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
