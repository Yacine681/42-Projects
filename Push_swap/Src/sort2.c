/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:40:53 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:11:30 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	push_last_bit_one(t_element **a, t_element **b, int size, int bit)
{
	int		i;
	int		nbr;

	i = 0;
	while (i < size)
	{
		nbr = (*a)->nb;
		if (((nbr >> bit) & 1) == 0)
			push_b(a, b);
		else
			rotate_a(a);
		i++;
	}
}

void	sort_big_stack(t_element **stack_a, t_element **stack_b)
{
	int			num_max;
	int			bit;

	if (!check_tri(stack_a))
	{
		num_max = ft_strlen_list(*stack_a);
		bit = 0;
		while (num_max >> bit)
		{
			push_last_bit_one(stack_a, stack_b, ft_strlen_list(*stack_a), bit);
			while (*stack_b)
				push_a(stack_a, stack_b);
			bit++;
		}
	}
}
