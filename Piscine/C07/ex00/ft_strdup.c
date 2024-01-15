/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:46:15 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 13:09:27 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned int	a;
	int				b;
	char			*memoire;

	b = 0;
	while (src[b])
		b++;
	memoire = malloc(sizeof(char) * b + 1);
	if (memoire == NULL)
		return (NULL);
		a = 0;
	while (src[a] != '\0')
	{
		memoire[a] = src[a];
		a++;
	}
		memoire[a] = '\0';
	return (memoire);
}