/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:52:11 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/21 03:29:21 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_neighbors(t_philo *philo, int *neighbors)
{
	neighbors[LEFT_PHILO] = philo->index;
	if (philo->index == 0)
		neighbors[RIGHT_PHILO] = philo->shared->philos_num - 1;
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
	if (philo->shared->philos_num == 2)
	{
		pthread_mutex_unlock(&philo->shared->forks_arr[0]);
		return ;
	}
	pthread_mutex_unlock(&philo->shared->forks_arr[neighbors[LEFT_PHILO]]);
	pthread_mutex_unlock(&philo->shared->forks_arr[neighbors[RIGHT_PHILO]]);
	return ;
}

int	locking_forks(t_philo *philo, int *neighbors)
{
	usleep(philo->id);
	if (philo->shared->philos_num == 1)
		return (0);
	else if (philo->shared->philos_num == 2 && \
	!philo->shared->forks_arr[0].__data.__lock)
	{
		pthread_mutex_lock(&philo->shared->forks_arr[0]);
		return (1);
	}
	else if (philo->shared->philos_num >= 3 && \
	!philo->shared->forks_arr[neighbors[LEFT_PHILO]].__data.__lock && \
	!philo->shared->forks_arr[neighbors[RIGHT_PHILO]].__data.__lock)
	{
		pthread_mutex_lock(&philo->shared->forks_arr[neighbors[LEFT_PHILO]]);
		pthread_mutex_lock(&philo->shared->forks_arr[neighbors[RIGHT_PHILO]]);
		return (1);
	}
	return (0);
}
