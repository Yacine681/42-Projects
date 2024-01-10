/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:49:51 by yabed             #+#    #+#             */
/*   Updated: 2022/10/16 11:53:55 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_philo(unsigned int time_to)
{
	unsigned int	awake;

	awake = get_time();
	while (get_time() < awake + time_to)
		usleep(1000);
}

void	is_max_ate(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->number_of_times_philo != -1 && i < philo->nb_philo
		&& is_all_ate(&philo->philo_1[i]))
		i++;
	if (i == philo->nb_philo)
	{
		pthread_mutex_lock(&philo->end_mutex);
		philo->end_sim = 1;
		pthread_mutex_unlock(&philo->end_mutex);
	}
}

static	int	print_death(t_philo *philo, int i)
{
	unsigned int	time;

	pthread_mutex_lock(&philo->msg_mutex);
	time = get_time() - philo->time;
	printf("%u %d %s\n", time, philo->philo_1[i].philo_id, "died");
	pthread_mutex_unlock(&philo->msg_mutex);
	return (1);
}

int	check_death(t_philo *philo)
{
	int	i;
	int	d;

	d = 0;
	while (!end_simulation(philo))
	{
		i = -1;
		while (++i < philo->nb_philo && !is_dead(philo))
		{
			pthread_mutex_lock(&philo->lastmeal_mutex);
			if (get_time() - philo->philo_1[i].lastmeal > philo->time_to_die)
			{
				pthread_mutex_lock(&philo->death_mutex);
				philo->died = 1;
				pthread_mutex_unlock(&philo->death_mutex);
				d = print_death(philo, i);
			}
			pthread_mutex_unlock(&philo->lastmeal_mutex);
		}
		if (is_dead(philo))
			break ;
		is_max_ate(philo);
		usleep(1000);
	}
	return (d);
}
