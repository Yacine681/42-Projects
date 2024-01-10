/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:52:20 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:11:19 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	sort_4(t_element **stack_a, t_element **stack_b)
{
	if (!check_tri(stack_a))
	{
		tri_min_4(stack_a);
		push_b(stack_a, stack_b);
		sort_3(stack_a);
		push_a(stack_a, stack_b);
	}
}

void	sort_5(t_element **stack_a, t_element **stack_b)
{
	if (!check_tri(stack_a))
	{
		tri_min_5(stack_a);
		push_b(stack_a, stack_b);
		sort_4(stack_a, stack_b);
		push_a(stack_a, stack_b);
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			swap_a(*stack_a);
	}
}
