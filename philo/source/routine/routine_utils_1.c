/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:52:11 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/23 18:52:30 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_neighbors(t_philo *philo, int *neighbors)
{
	if (philo->shared->max_philos == 2)
	{
		neighbors[LEFT_PHILO] = 0;
		neighbors[RIGHT_PHILO] = 1;
		return ;
	}
	neighbors[LEFT_PHILO] = philo->index;
	if (philo->index == 0)
		neighbors[RIGHT_PHILO] = philo->shared->max_philos - 1;
	else
		neighbors[RIGHT_PHILO] = philo->index - 1;
}

long int	get_clock(long int start_time)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - start_time);
}

void	unlocking_forks(t_philo *philo, int *neighbors)
{
	pthread_mutex_unlock(&philo->shared->forks_arr[neighbors[LEFT_PHILO]]);
	pthread_mutex_unlock(&philo->shared->forks_arr[neighbors[RIGHT_PHILO]]);
	return ;
}

int	locking_forks(t_philo *philo, int *neighbors)
{
	if (philo->shared->max_philos == 1)
		return (0);
	if (philo->shared->priority == philo->id && \
	!philo->shared->forks_arr[neighbors[LEFT_PHILO]].__data.__lock && \
	!philo->shared->forks_arr[neighbors[RIGHT_PHILO]].__data.__lock)
	{
		pthread_mutex_lock(&philo->shared->forks_arr[neighbors[LEFT_PHILO]]);
		pthread_mutex_lock(&philo->shared->forks_arr[neighbors[RIGHT_PHILO]]);
		return (1);
	}
	return (0);
}

