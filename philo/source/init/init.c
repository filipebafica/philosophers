/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:37:39 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/23 21:58:37 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_shared *shared)
{
	t_philo		*philo;
	int			i;

	pthread_create(&shared->dead_philo_th, NULL, &get_dead_philo, shared);
	pthread_create(&shared->full_philo_th, NULL, &get_full_philo, shared);
	pthread_create(&shared->full_philo_th, NULL, &get_priority, shared);
	shared->start_time = get_start_time();
	i = 0;
	while (i < shared->max_philos)
	{
		philo = malloc(sizeof(t_philo));
		philo->id = i + 1;
		philo->index = i;
		philo->status = 0;
		if (philo->id % 2 == 0)
			philo->delay = 5;
		else
			philo->delay = 0;
		philo->shared = shared;
		pthread_create(shared->philos_arr + i, NULL, &routine, philo);
		++i;
	}
}

void	wait_threads(t_shared *shared)
{
	int	i;

	pthread_join(shared->dead_philo_th, NULL);
	pthread_join(shared->full_philo_th, NULL);
	pthread_join(shared->priority_th, NULL);
	i = 0;
	while (i < shared->max_philos)
	{
		pthread_join(shared->philos_arr[i], NULL);
		++i;
	}
}

void	init_mutex(t_shared *shared)
{
	int	i;

	pthread_mutex_init(&shared->print_mutex, NULL);
	i = 0;
	while (i < shared->max_philos)
	{
		pthread_mutex_init(&shared->forks_arr[i], NULL);
		++i;
	}
}

void	destroy_mutex(t_shared *shared)
{
	int	i;

	pthread_mutex_destroy(&shared->print_mutex);
	i = 0;
	while (i < shared->max_philos)
	{
		pthread_mutex_destroy(&shared->forks_arr[i]);
		++i;
	}
}
