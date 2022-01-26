/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:53:47 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/24 14:01:49 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleeping(t_philo *philo)
{
	while (!stop_philo(philo->shared, philo->index) && \
	philo->status != SLEEPING)
	{
		if (print_status(philo->shared, philo->id, PRINT_SLEEPING, 1))
		{
			philo->status = SLEEPING;
			usleep(philo->shared->time_to_sleep * 1000);
		}
	}
}

static void	eating(t_philo *philo, int *neighbors)
{
	while (!stop_philo(philo->shared, philo->index) && \
	philo->status != TAKEN_FORK)
	{
		if (print_status(philo->shared, philo->id, PRINT_TAKEN_FORK, 2))
			philo->status = TAKEN_FORK;
	}
	while (!stop_philo(philo->shared, philo->index) && \
	philo->status != EATING)
	{
		if (print_status(philo->shared, philo->id, PRINT_EATING, 1))
		{
			philo->shared->meal_time_arr[philo->index] = \
			get_clock(philo->shared->start_time);
			philo->status = EATING;
			philo->shared->num_meals_arr[philo->index] += 1;
			usleep(philo->shared->time_to_eat * 1000);
		}
	}
	unlocking_forks(philo, neighbors);
}

static int	thinking(t_philo *philo, int *neighbors)
{
	if (!stop_philo(philo->shared, philo->index) && \
	locking_forks(philo, neighbors))
		return (1);
	while (!stop_philo(philo->shared, philo->index) && \
	philo->status != THINKING)
	{
		if (print_status(philo->shared, philo->id, PRINT_THINKING, 1))
			philo->status = THINKING;
	}
	usleep(500);
	return (0);
}

void	*routine(void *args)
{
	t_philo		*philo;
	int			neighbors[2];

	philo = (t_philo *)args;
	set_neighbors(philo, neighbors);
	usleep(philo->delay * 1000);
	while (1)
	{
		if (thinking(philo, neighbors))
		{
			eating(philo, neighbors);
			sleeping(philo);
		}
		if (stop_philo(philo->shared, philo->index))
			break ;
	}
	free(philo);
	return (NULL);
}
