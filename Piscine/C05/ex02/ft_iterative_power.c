/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:49:48 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:59:01 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	a;
	int	resultat;

	a = 1;
	resultat = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (a < power)
	{
			resultat *= nb;
			a++;
	}
	return (resultat);
}