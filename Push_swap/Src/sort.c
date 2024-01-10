/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:10:37 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:11:05 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	sort_2(t_element **stack_a)
{
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		swap_a(*stack_a);
}

void	sort_3(t_element **stack_a)
{
	t_element	*tmp1;

	tmp1 = *stack_a;
	if (tmp1->nb > tmp1->next->nb && tmp1->nb > tmp1->next->next->nb)
	{
		if (tmp1->next->nb < tmp1->next->next->nb)
			rotate_a(stack_a);
		else
		{
			rotate_a(stack_a);
			swap_a(*stack_a);
		}
	}
	else if (tmp1->nb < tmp1->next->nb && tmp1->next->nb > tmp1->next->next->nb)
	{
		if (tmp1->nb < tmp1->next->next->nb)
		{
			reverse_a(stack_a);
			swap_a(*stack_a);
		}
		else
			reverse_a(stack_a);
	}
	else if (tmp1->nb > tmp1->next->nb && tmp1->next->nb < tmp1->next->next->nb)
		swap_a(*stack_a);
}
