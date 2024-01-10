/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:59:04 by yabed             #+#    #+#             */
/*   Updated: 2024/01/10 13:42:14 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	ft_exit(t_philo	*philo, int nb)
{
	if (nb == 1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (argc > 6 || argc < 5)
	{
		printf("Error: Incorrect number of arguments\nUsage: ./philo philo_count time_to_die time_to_eat time_to_sleep [option: must_eat_count]\n");
		ft_exit(philo, 0);
	}
	else if (check_argument(argv))
		ft_exit(philo, 0);
	else
	{
		init_param(philo, argv, argc);
		if (check_nb_philo(philo))
		{
			printf("Invalid Arguments\n");
			ft_exit(philo, 0);
		}
		start_simulation(philo);
		if (check_death(philo))
			ft_exit(philo, 1);
		join_threads(philo);
		destroy_mutexes(philo);
	}
	return (0);
}
