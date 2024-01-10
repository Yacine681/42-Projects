/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:11:18 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:10:17 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

void	createlist(t_element **L, int nbr)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (!element)
		exit (EXIT_FAILURE);
	element->nb = nbr;
	element->next = NULL;
	ft_lstadd_back(L, element);
}

void	ft_lstadd_front(t_element **lst, t_element *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_strlen_list(t_element *L)
{
	int	i;

	i = 0;
	while (L)
	{
		L = L->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_element **lst, t_element *new)
{
	t_element	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
