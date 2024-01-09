/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:58:23 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:25 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{	
		f(i, &s[i]);
		++i;
	}
}
