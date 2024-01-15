/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:44:48 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:58:44 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	a;
	int	resultat;

	a = 1;
	resultat = 1;
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	while (a <= nb)
	{
		resultat = a * resultat;
		a++;
	}
	return (resultat);
}