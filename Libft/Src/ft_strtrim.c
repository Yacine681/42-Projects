/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:35:27 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:07 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

static int	flag(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_subtrim(char const *s, unsigned int start, size_t len)
{
	int		a;
	size_t	b;
	char	*str;

	a = 0;
	b = start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (len - (start)+2));
	if (!str)
		return (NULL);
	while (s[start] && b <= len)
	{
		str[a] = s[b];
		a++;
		b++;
	}
	str[a] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	char	*dst;

	if (!s1)
		return (NULL);
	a = 0;
	b = ft_strlen(s1);
	while (flag(set, s1[a]))
		a++;
	if (a == b)
		return (ft_strdup(""));
	while ((s1[b] == '\0') || flag(set, s1[b]))
		b--;
	if (b < 0)
		return (ft_strdup(""));
	dst = ft_subtrim(s1, a, b);
	return (dst);
}
