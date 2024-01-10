/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:44:07 by yabed             #+#    #+#             */
/*   Updated: 2022/10/16 11:45:21 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_init(&philo->msg_mutex, NULL);
	pthread_mutex_init(&philo->end_mutex, NULL);
	pthread_mutex_init(&philo->eat_mutex, NULL);
	pthread_mutex_init(&philo->death_mutex, NULL);
	pthread_mutex_init(&philo->lastmeal_mutex, NULL);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	while (i < philo->nb_philo)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		i++;
	}
}

void	init_param(t_philo *philo, char **argv, int argc)
{
	philo->nb_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_philo = ft_atoi(argv[5]);
	else
		philo->number_of_times_philo = -1;
	philo->died = 0;
	init_mutexes(philo);
}
