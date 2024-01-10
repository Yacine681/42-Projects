/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:12:11 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:10:04 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	push_swap(t_element **stack_a, t_element **stack_b, t_element **tmp)
{
	ft_neg_to_pos(stack_a, tmp);
	stack_tmp_to_stack_a(stack_a, tmp);
	ft_tri_stack(stack_a, stack_b, ft_strlen_list(*stack_a));
	ft_free(stack_a);
	ft_free(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	push;

	if (argc > 2)
	{
		while (argv[++push.i])
		{
			if (check_error(&argv[push.i]))
				error();
			createlist(&push.stack_a, ft_atoi(argv[push.i]));
		}
	}
	if (argc == 2)
	{
		push.nb = ft_split(argv[1], ' ');
		while (push.nb[push.i])
		{
			if (check_error(push.nb))
				error();
			createlist(&push.stack_a, ft_atoi(push.nb[push.i++]));
		}
	}
	if (double_0(&push.stack_a))
		error();
	push_swap(&push.stack_a, &push.stack_b, &push.stack_tmp);
	return (0);
}
