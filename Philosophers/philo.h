/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:51:44 by yabed             #+#    #+#             */
/*   Updated: 2022/10/16 13:15:05 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_utils	t_utils;

typedef struct s_philo
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_philo;
	int				nb_eat;
	int				end_sim;
	int				died;
	unsigned int	time;
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	lastmeal_mutex;
	pthread_mutex_t	*fork;
	t_utils			*philo_1;
}	t_philo;

struct	s_utils
{
	int				philo_id;
	int				left_i;
	int				right_i;
	pthread_t		tid;
	int				ate_times;
	t_philo			*philo;
	long int		lastmeal;
};

int					ft_atoi(char *str);
int					is_dead(t_philo *philo);
int					is_all_ate(t_utils *philo);
int					check_death(t_philo *philo);
int					check_argument(char **argv);
int					end_simulation(t_philo *philo);
int					check_nb_philo(t_philo *philo);

unsigned int		get_time(void);

void				*start(void *data);
void				init_mutexes(t_philo *philo);
void				join_threads(t_philo *philo);
void				destroy_mutexes(t_philo *philo);
void				start_simulation(t_philo *philo);
void				start_simulation(t_philo *philo);
void				sleep_philo(unsigned int time_to);
void				init_param(t_philo *philo, char **argv, int argc);
#endif
