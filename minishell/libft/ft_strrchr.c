/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:22:21 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 14:43:16 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	int		nb;

	a = -1;
	nb = -1;
	while (s[++a])
		if (s[a] == c)
			nb = a;
	if (s[a] == c)
		nb = a;
	if (nb > -1)
		return (((char *)s) + nb);
	return (NULL);
}
