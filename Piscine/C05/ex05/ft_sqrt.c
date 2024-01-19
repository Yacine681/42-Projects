/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:16:34 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:59:24 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	a;

	a = 0;
	if ((nb % 1 != 0) || (nb == 0))
		return (0);
	while ((a * a < nb) && (a < 46340))
		a++;
	if (a * a == nb)
		return (a);
	return (0);
}	