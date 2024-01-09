/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 08:30:31 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:24 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*str;

	if (!s1 || !s2)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	a = 0;
	while (s2[a])
	{
		str[i++] = s2[a];
		a++;
	}
	str[i] = '\0';
	return (str);
}	
