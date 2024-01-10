/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:21:43 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:10:02 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	ft_tri_stack(t_element **stack_a, t_element **stack_b, int argc)
{
	if (argc == 2)
		sort_2(stack_a);
	else if (argc == 3)
		sort_3(stack_a);
	else if (argc == 4)
		sort_4(stack_a, stack_b);
	else if (argc == 5)
		sort_5(stack_a, stack_b);
	else if (argc > 5)
		sort_big_stack(stack_a, stack_b);
}
