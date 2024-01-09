/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:21:18 by yabed             #+#    #+#             */
/*   Updated: 2022/08/17 21:08:52 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122)
		|| (c >= 65 && c <= 90))
		return (1);
	return (0);
}
