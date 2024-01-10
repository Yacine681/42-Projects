/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:39:02 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:42:45 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		c;
	char	*str;

	c = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		str[c] = s1[a];
		a++;
		c++;
	}
	b = 0;
	while (s2[b])
	{
		str[c] = s2[b];
		b++;
		c++;
	}
	str[c] = '\0';
	return (str);
}
