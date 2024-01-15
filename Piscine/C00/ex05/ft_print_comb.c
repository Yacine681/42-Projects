/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:11:45 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:54:24 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_putchar(char c);
void	ft_print(int i, int j, int k);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int i, int j, int k)
{
	if (i == '7' && j == '8' && k == '9')
	{
		write(1, "789", 3);
		k++;
	}
	else
	{
		ft_putchar(i);
		ft_putchar(j);
		ft_putchar(k);
		ft_putchar(44);
		ft_putchar(32);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 48;
	j = 49;
	k = 50;
	while (i <= 57)
	{
		while (j <= 57)
		{
			while (k <= 57)
			{
				ft_print(i, j, k);
				k++;
			}
			j++;
			k = j + 1;
		}
		i++;
		j = i;
	}
}