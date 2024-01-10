/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:31:33 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:12:24 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_element
{
	int					nb;
	struct s_element	*next;
}						t_element;

typedef struct s_list
{
	t_element	*stack_a;
	t_element	*stack_b;
	t_element	*stack_tmp;
	int			i;
	char		**nb;
}				t_list;

void	createlist(t_element **L, int nbr);

void	swap_a(t_element *stack_a);
void	swap_b(t_element *stack_b);
void	swap_ss(t_element *stack_a, t_element *stack_b);

void	push_a(t_element **stack_a, t_element **stack_b);
void	push_b(t_element **stack_a, t_element **stack_b);

void	rotate_a(t_element **stack_a);
void	rotate_b(t_element **stack_b);
void	rotate_rr(t_element **stack_a, t_element **stack_b);

void	reverse_a(t_element **stack_a);
void	reverse_b(t_element **stack_b);
void	reverse_rrr(t_element **stack_a, t_element **stack_b);

void	sort_2(t_element **stack_a);
void	sort_3(t_element **stack_a);
void	sort_4(t_element **stack_a, t_element **stack_b);
void	sort_5(t_element **stack_a, t_element **stack_b);
void	sort_big_stack(t_element **stack_a, t_element **stack_b);

void	ft_free(t_element **stack);
void	tri_min_4(t_element **stack_a);
void	tri_min_5(t_element **stack_a);
void	ft_lstadd_back(t_element **lst, t_element *new);
void	ft_lstadd_front(t_element **lst, t_element *new);
void	ft_neg_to_pos(t_element **stack_a, t_element **stack_tmp);
void	ft_tri_stack(t_element **stack_a, t_element **stack_b, int nb);
void	stack_tmp_to_stack_a(t_element **stack_a, t_element **stack_tmp);

int		check_error(char **argv);
int		ft_atoi(const char *str);
int		is_empty_list(t_element *L);
int		ft_strlen_list(t_element *L);
int		double_0(t_element **stack_a);
int		find_min(t_element **stack_a);
int		check_tri(t_element **stack_a);

size_t	ft_strlen(const char *str);

char	**ft_split(char const *s, char c);
#endif
