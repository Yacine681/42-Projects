/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:55:40 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:58:34 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_space(char *str, int *a, int b)
{
	while (str[*a] == '\t' || str[*a] == '\n' || str[*a] == '\v'
		|| str[*a] == '\f' || str[*a] == '\r' || str[*a] == ' ')
		*a = *a + 1;
	while (str[*a] == '-' || str[*a] == '+')
	{
		if (str[*a] == '-')
			b *= -1;
	*a = *a + 1;
	}
	return (b);
}

int	ft_atoi(char *str)
{
	int	a;
	int	b;
	int	res;

	a = 0;
	b = 1;
	res = 0;
	b = ft_space(str, &a, b);
	while (str)
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			res *= 10;
			res += str[a] - '0';
		}
		else
		{	
			return (res * b);
		}
	a++;
	}
	return (res * b);
}