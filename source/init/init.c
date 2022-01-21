/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:37:39 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/21 03:26:51 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_shared *shared)
{
	t_philo		*philo;
	int			i;

	pthread_create(&shared->dead_philo_th, NULL, &get_dead_philo, shared);
	pthread_create(&shared->full_philo_th, NULL, &get_full_philo, shared);
	i = 0;
	while (i < shared->philos_num)
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
	i = 0;
	while (i < shared->philos_num)
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
	while (i < shared->philos_num)
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
	while (i < shared->philos_num)
	{
		pthread_mutex_destroy(&shared->forks_arr[i]);
		++i;
	}
}
