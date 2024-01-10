/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:49:51 by yabed             #+#    #+#             */
/*   Updated: 2022/10/16 11:18:01 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->death_mutex);
	if (philo->died)
	{
		pthread_mutex_unlock(&philo->death_mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->death_mutex);
		return (0);
	}
}

int	end_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->end_mutex);
	if (philo->end_sim)
	{
		pthread_mutex_unlock(&philo->end_mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->end_mutex);
		return (0);
	}
}

int	is_all_ate(t_utils *philo)
{
	pthread_mutex_lock(&philo->philo->eat_mutex);
	if (philo->ate_times >= philo->philo->number_of_times_philo)
	{
		pthread_mutex_unlock(&philo->philo->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo->eat_mutex);
	return (0);
}
