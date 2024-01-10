/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:49:51 by yabed             #+#    #+#             */
/*   Updated: 2022/10/16 11:51:55 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	philo->philo_1 = malloc(sizeof(t_utils) * philo->nb_philo);
	while (i < philo->nb_philo)
	{
		philo->philo_1[i].philo_id = i + 1;
		philo->philo_1[i].philo = philo;
		philo->philo_1[i].ate_times = 0;
		philo->philo_1[i].right_i = i;
		philo->philo_1[i].left_i = (i + 1) % philo->nb_philo;
		philo->philo_1[i].lastmeal = 0;
		i++;
	}
}

void	start_simulation(t_philo *philo)
{
	int	i;

	i = 0;
	init_philo(philo);
	philo->time = get_time();
	while (i < philo->nb_philo)
	{
		philo->philo_1[i].lastmeal = philo->time;
		if (pthread_create(&philo->philo_1[i].tid, NULL,
				&start, &philo->philo_1[i]))
			printf("Failed to create Thread\n");
		i++;
	}
}

void	join_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (pthread_join(philo->philo_1[i].tid, NULL))
			printf("Failed to Join Thread\n");
		i++;
	}
	free(philo->fork);
	free(philo->philo_1);
}
