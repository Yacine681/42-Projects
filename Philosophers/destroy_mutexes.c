/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:44:07 by yabed             #+#    #+#             */
/*   Updated: 2022/10/16 11:44:36 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->msg_mutex);
	pthread_mutex_destroy(&philo->end_mutex);
	pthread_mutex_destroy(&philo->eat_mutex);
	pthread_mutex_destroy(&philo->death_mutex);
	pthread_mutex_destroy(&philo->lastmeal_mutex);
	while (i < philo->nb_philo)
	{
		pthread_mutex_destroy(&philo->fork[i]);
		i++;
	}
}
