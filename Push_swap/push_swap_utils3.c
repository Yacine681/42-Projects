/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:45:48 by yabed             #+#    #+#             */
/*   Updated: 2024/01/18 11:52:12 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

int	double_0(t_element **stack_a)
{
	int			i;
	t_element	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp->nb == 0)
			i++;
		tmp = tmp->next;
	}
	if (i > 1)
		return (1);
	return (0);
}

void	ft_free(t_element **stack)
{
	t_element	*current;
	t_element	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	ft_neg_to_pos(t_element **stack_a, t_element **stack_tmp)
{
	int			i;
	t_element	*tmp1;
	t_element	*tmp2;

	i = 0;
	tmp1 = *stack_a;
	tmp2 = *stack_a;
	while (tmp2 != NULL)
	{
		if (tmp1->nb > tmp2->nb)
			i++;
		if (tmp2->next == NULL)
		{
			createlist(stack_tmp, i);
			i = 0;
			tmp1 = tmp1->next;
			tmp2 = *stack_a;
		}
		else
			tmp2 = tmp2->next;
		if (tmp1 == NULL)
			break ;
	}
}

void	stack_tmp_to_stack_a(t_element **stack_a, t_element **stack_tmp)
{
	*stack_a = *stack_tmp;
}
