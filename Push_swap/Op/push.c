/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:27:51 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:12:14 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	push_a(t_element **stack_a, t_element **stack_b)
{
	t_element	*tmp1;
	t_element	*tmp2;

	if (!is_empty_list(*stack_b))
	{
		tmp1 = *stack_b;
		tmp2 = *stack_b;
		tmp2 = tmp2->next;
		ft_lstadd_front(stack_a, tmp1);
		*stack_b = tmp2;
		write(1, "pa\n", 3);
	}
	else
		return ;
}

void	push_b(t_element **stack_a, t_element **stack_b)
{
	t_element	*tmp1;
	t_element	*tmp2;

	if (!is_empty_list(*stack_a))
	{
		tmp1 = *stack_a;
		tmp2 = *stack_a;
		tmp2 = tmp2->next;
		ft_lstadd_front(stack_b, tmp1);
		*stack_a = tmp2;
		write(1, "pb\n", 3);
	}
	else
		return ;
}
