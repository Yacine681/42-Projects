/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:58:57 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:39:30 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_len(unsigned int n)
{
	size_t	count_len;

	count_len = 0;
	if (n == 0)
	count_len++;
	while (n > 0)
	{
		n /= 16;
		count_len++;
	}
	return (count_len);
}

char	*ft_itoa_hex(unsigned int n, int upper)
{
	char	*lowercase;
	char	*uppercase;
	char	*dst;
	size_t	len;

	lowercase = "0123456789abcdef";
	uppercase = "0123456789ABCDEF";
	len = ft_count_len(n);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	if (n == 0)
		dst[0] = '0';
	while (n > 0)
	{
		if (upper == 1)
			dst[len - 1] = uppercase[n % 16];
		else
			dst[len - 1] = lowercase[n % 16];
		n /= 16;
		len--;
	}
	return (dst);
}
