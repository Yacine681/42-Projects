/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:24:29 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:18 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		++i;
	}
	str[i] = '\0';
	return (str);
}
