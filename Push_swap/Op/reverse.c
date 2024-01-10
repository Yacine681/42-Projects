/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:40:46 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:12:05 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static	void	reverse(t_element **reverse)
{
	t_element		*tmp1;
	t_element		*i;

	tmp1 = *reverse;
	i = *reverse;
	while (tmp1->next != NULL)
	tmp1 = tmp1->next;
	while (i->next->next != NULL)
	i = i->next;
	i->next = NULL;
	tmp1->next = *reverse;
	ft_lstadd_front(reverse, tmp1);
}	

void	reverse_a(t_element **stack_a)
{
	t_element		*tmp1;
	t_element		*i;

	tmp1 = *stack_a;
	i = *stack_a;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	while (i->next->next != NULL)
		i = i->next;
	i->next = NULL;
	tmp1->next = *stack_a;
	ft_lstadd_front(stack_a, tmp1);
	write(1, "rra\n", 4);
}

void	reverse_b(t_element **stack_b)
{
	t_element		*tmp1;
	t_element		*i;

	tmp1 = *stack_b;
	i = *stack_b;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	while (i->next->next != NULL)
		i = i->next;
	i->next = NULL;
	tmp1->next = *stack_b;
	ft_lstadd_front(stack_b, tmp1);
	write(1, "rrb\n", 4);
}

void	reverse_rrr(t_element **stack_a, t_element **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
}
