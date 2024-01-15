/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:51:26 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:57:38 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (dest[a])
		a++;
	while (src[b] != '\0' && nb > b)
	{
			dest[a + b] = src [b];
			b++;
	}	
	dest[a + b] = '\0';
	return (dest);
}