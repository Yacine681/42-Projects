/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:03:56 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:11:44 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static	void	swap(t_element *swap)
{
	int	tmp;

	if (!is_empty_list(swap))
	{
		tmp = swap->nb;
		swap->nb = swap->next->nb;
		swap->next->nb = tmp;
	}
	else
		return ;
}

void	swap_a(t_element *stack_a)
{
	int	tmp;

	if (!is_empty_list(stack_a))
	{
		tmp = stack_a->nb;
		stack_a->nb = stack_a->next->nb;
		stack_a->next->nb = tmp;
		write(1, "sa\n", 3);
	}
	else
		return ;
}

void	swap_b(t_element *stack_b)
{
	int	tmp;

	if (!is_empty_list(stack_b))
	{
		tmp = stack_b->nb;
		stack_b->nb = stack_b->next->nb;
		stack_b->next->nb = tmp;
		write(1, "sb\n", 3);
	}
	else
		return ;
}

void	swap_ss(t_element *stack_a, t_element *stack_b)
{
	if (!is_empty_list(stack_a) || !is_empty_list(stack_b))
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
	else
		return ;
}
