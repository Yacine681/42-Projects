/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:29:18 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:43:25 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = start;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] && len)
	{
		str[a] = s[b];
		a++;
		b++;
		len--;
	}
	str[a] = '\0';
	return (str);
}
