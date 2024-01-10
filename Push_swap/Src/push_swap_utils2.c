/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:55:53 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:10:42 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

int	is_empty_list(t_element *L)
{
	return (L == NULL);
}

int	find_min(t_element **stack_a)
{
	int			nb;
	t_element	*tmp;

	tmp = *stack_a;
	nb = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < nb)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	return (nb);
}

void	tri_min_4(t_element **stack_a)
{
	int			nb;

	nb = 0;
	nb = find_min(stack_a);
	if (nb == (*stack_a)->next->nb)
		swap_a(*stack_a);
	else if (nb == (*stack_a)->next->next->nb)
	{
		reverse_a(stack_a);
		reverse_a(stack_a);
	}
	else if (nb == (*stack_a)->next->next->next->nb)
		reverse_a(stack_a);
}

void	tri_min_5(t_element **stack_a)
{	
	int			nb;

	nb = 0;
	nb = find_min(stack_a);
	if (nb == (*stack_a)->next->nb)
		swap_a(*stack_a);
	else if (nb == (*stack_a)->next->next->nb)
	{
		rotate_a(stack_a);
		swap_a(*stack_a);
	}
	else if (nb == (*stack_a)->next->next->next->nb)
	{
		reverse_a(stack_a);
		reverse_a(stack_a);
	}
	else if (nb == (*stack_a)->next->next->next->next->nb)
		reverse_a(stack_a);
}

int	check_tri(t_element **stack_a)
{
	t_element	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (!(tmp->nb < tmp->next->nb))
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
}
