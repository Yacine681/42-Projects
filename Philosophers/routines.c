/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:49:51 by yabed             #+#    #+#             */
/*   Updated: 2022/10/16 11:50:32 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	print_msg(char *str, t_utils *philo_1)
{
	unsigned int	time_ms;

	pthread_mutex_lock(&philo_1->philo->msg_mutex);
	if (!is_dead(philo_1->philo) && !end_simulation(philo_1->philo))
	{
		time_ms = get_time() - philo_1->philo->time;
		printf("%u %d %s\n", time_ms, philo_1->philo_id, str);
	}
	pthread_mutex_unlock(&philo_1->philo->msg_mutex);
}

static	void	eat_routine(t_utils *philo)
{
	pthread_mutex_lock(&philo->philo->fork[philo->left_i]);
	print_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->philo->fork[philo->right_i]);
	print_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->philo->lastmeal_mutex);
	philo->lastmeal = get_time();
	print_msg("is eating", philo);
	pthread_mutex_unlock(&philo->philo->lastmeal_mutex);
	sleep_philo(philo->philo->time_to_eat);
	pthread_mutex_lock(&philo->philo->eat_mutex);
	philo->ate_times++;
	pthread_mutex_unlock(&philo->philo->eat_mutex);
	pthread_mutex_unlock(&philo->philo->fork[philo->left_i]);
	pthread_mutex_unlock(&philo->philo->fork[philo->right_i]);
}

void	*start(void *data)
{
	t_utils	*philo;

	philo = (t_utils *)data;
	if (philo->philo_id % 2 == 0)
		usleep(100);
	while (1)
	{
		eat_routine(philo);
		if (end_simulation(philo->philo))
			break ;
		print_msg("is sleeping", philo);
		sleep_philo(philo->philo->time_to_sleep);
		print_msg("is thinking", philo);
	}
	return (NULL);
}
