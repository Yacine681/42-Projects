/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:54:05 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:42:36 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*str;

	a = ft_strlen(s1);
	str = malloc(sizeof(char) * (a + 1));
	if (!str)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		str[a] = ((char *)s1)[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}
