/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:01:53 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:27 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	a;
	int				b;
	char			*memoire;

	b = 0;
	while (s1[b])
		b++;
	memoire = malloc(sizeof(char) * b + 1);
	if (memoire == NULL)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		memoire[a] = s1[a];
		a++;
	}
	memoire[a] = '\0';
	return (memoire);
}
