/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:48:49 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:39:30 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_str(char *s, char *ins, int pos)
{
	char	*new;
	char	*swap;
	int		len;

	swap = ft_strnew(ft_strlen(s));
	ft_strncpy(swap, s, pos);
	len = ft_strlen(swap);
	ft_strcpy(swap + len, ins);
	len += ft_strlen(ins);
	ft_strcpy(swap + len, s + pos);
	new = ft_strcpy (s, swap);
	free (swap);
	return (new);
}
