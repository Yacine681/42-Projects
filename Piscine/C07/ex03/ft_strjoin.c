/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:47:16 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 13:10:16 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	char	*tab;
	int		a;
	int		b;
	int		c;
	int		count;

	a = 0;
	b = 0;
	c = 0;
	count = 1;
	while (a < size)
		count += ft_strlen(strs[a++]) + ft_strlen(sep);
	tab = malloc(sizeof(char *) * count);
	a = -1;
	while (++a < size)
	{
		while (strs[a][b])
			tab[c++] = strs[a][b++];
		b = 0;
		while (sep[b] && a < size -1)
			tab[c++] = sep[b++];
		b = 0;
	}
	tab[c] = '\0';
	return (tab);
}