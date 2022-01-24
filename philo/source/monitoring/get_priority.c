/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_priority.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:20:21 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/23 22:02:14 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long int	get_lowest_meal_time (t_shared *shared)
{
	int			i;
	long int	meal_time;

	i = 0;
	meal_time = 2147483647;
	while (i < shared->max_philos)
	{
		if (shared->meal_time_arr[i] && \
		shared->meal_time_arr[i] < meal_time && \
		shared->satisfied_arr[i] != FULL)
			meal_time = shared->meal_time_arr[i];
		++i;
	}
	return (meal_time);
}

static int	get_neighbor(int curr_index, int max_philos)
{
	if (max_philos == 2)
		return (1);
	else if (curr_index == 0)
		return(max_philos - 1);
	else
		return (curr_index - 1);
}

void	*get_priority(void *args)
{
	t_shared	*shared;
	int			neighbor;
	int			i;
	long int	meal_time;

	shared = (t_shared *)args;
	while (!shared->stop_simulation)
	{
		i = 0;
		while (i < shared->max_philos)
		{
			neighbor = get_neighbor(i, shared->max_philos);
			meal_time = get_lowest_meal_time(shared);
			if (shared->meal_time_arr[i] <= meal_time && \
			!shared->forks_arr[i].__data.__lock && \
			!shared->forks_arr[neighbor].__data.__lock)
				shared->priority = i + 1;
			printf("%6ld  %6d  neighbor: %d  priority: %d philo_meal_time: %6ld  meal_time: %6ld\n", get_clock(shared->start_time), i + 1, neighbor, shared->priority, shared->meal_time_arr[i], meal_time);
			++i;
		}
		usleep(250);
	}
	return (NULL);
}
