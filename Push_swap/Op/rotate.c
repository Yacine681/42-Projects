/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:21:37 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:11:55 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static	void	rotate(t_element **rotate)
{
	t_element	*tmp1;

	tmp1 = (*rotate)->next;
	(*rotate)->next = NULL;
	ft_lstadd_back(&tmp1, *rotate);
	*rotate = tmp1;
}

void	rotate_a(t_element **stack_a)
{
	t_element	*tmp1;

	tmp1 = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lstadd_back(&tmp1, *stack_a);
	*stack_a = tmp1;
	write(1, "ra\n", 3);
}

void	rotate_b(t_element **stack_b)
{
	t_element	*tmp1;

	tmp1 = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lstadd_back(&tmp1, *stack_b);
	*stack_b = tmp1;
	write(1, "rb\n", 3);
}

void	rotate_rr(t_element **stack_a, t_element **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
