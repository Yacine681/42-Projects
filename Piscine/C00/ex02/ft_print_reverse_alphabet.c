/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:29:31 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:53:16 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	alphabet;
	int		i;

	i = 0;
	alphabet = 'z';
	while (i < 26)
	{
		write(1, &alphabet, 1);
		i++;
		alphabet--;
	}		
}