/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:55:26 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:09:48 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/push_swap.h"

static int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

static	int	check_caractere(char **argv)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i][a] == '-' || argv[i][a] == '+')
			a++;
		if (argv[i][a] == '\0')
			return (1);
		while (argv[i][a])
		{
			if (!ft_isdigit(argv[i][a]))
				return (1);
			a++;
		}
		i++;
		a = 0;
	}
	return (0);
}

static	int	check_doublons(char **argv)
{
	int	i;
	int	a;
	int	nb;

	i = 0;
	a = 1;
	nb = 0;
	while (argv[a])
	{
		while (argv[a])
		{	
			if (ft_atoi(argv[i]) == ft_atoi(argv[a]))
			{
				if (argv[a][0] == '0' && nb < 1)
					nb++;
				else
					return (1);
			}
			a++;
		}
		i++;
		a = i + 1;
	}
	return (0);
}

static	int	check_max_min(char *argv)
{
	if (argv[0] == '-')
	{	
		if (ft_atoi(argv) > 0)
			return (1);
	}
	else if (argv[0] != '-')
	{	
		if (ft_atoi(argv) < 0)
			return (1);
	}
	return (0);
}

int	check_error(char **argv)
{
	if (check_max_min(*argv) || check_doublons(argv) || check_caractere(argv))
		return (1);
	return (0);
}
