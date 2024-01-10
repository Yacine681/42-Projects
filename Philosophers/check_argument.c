/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:49:51 by yabed             #+#    #+#             */
/*   Updated: 2022/10/16 11:48:11 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	check_caractere(char **argv)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	while (argv[i])
	{
		while (argv[i][a])
		{
			if (!(argv[i][a] >= '0' && argv[i][a] <= '9'))
				return (1);
			a++;
		}
		i++;
		a = 0;
	}
	return (0);
}

static	int	check_neg(char **argv)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (argv[i])
	{
		while (argv[i][a])
		{
			if (ft_atoi(&argv[i][a]) < 0)
				return (1);
			a++;
		}
		i++;
		a = 0;
	}
	return (0);
}

static	int	check_zero(char **argv)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (argv[i])
	{
		while (argv[i][a])
		{
			if (argv[i][a] == '0')
			{
				if (ft_atoi(argv[i]) + 0 == 0)
					return (1);
			}
			a++;
		}
		i++;
		a = 0;
	}
	return (0);
}

int	check_nb_philo(t_philo *philo)
{
	if (philo->nb_philo > 200)
		return (1);
	return (0);
}

int	check_argument(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_neg(&argv[i]))
			return (write(2, "Error neg!\n", 11));
		else if (check_zero(&argv[i]))
			return (write(2, "Error Zero!\n", 12));
		else if (check_caractere(&argv[i]))
			return (write(2, "Error caracetere!\n", 18));
		i++;
	}
	return (0);
}
