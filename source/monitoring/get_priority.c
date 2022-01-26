/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_priority.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:20:21 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/24 14:05:03 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_min_num_meal(t_shared *shared)
{
	int	i;
	int	min_num_meal;

	i = 0;
	min_num_meal = 2147483647;
	while (i < shared->max_philos)
	{
		if (shared->num_meals_arr[i] < min_num_meal)
			min_num_meal = shared->num_meals_arr[i];
		++i;
	}
	return (min_num_meal);
}

static long int	get_lowest_meal_time(t_shared *shared)
{
	int			i;
	long int	meal_time;

	i = 0;
	meal_time = 2147483647;
	while (i < shared->max_philos)
	{
		if (shared->meal_time_arr[i] < meal_time && \
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
		return (max_philos - 1);
	else
		return (curr_index - 1);
}

void	*get_priority(void *args)
{
	t_shared	*shared;
	int			i;

	shared = (t_shared *)args;
	while (!shared->stop_simulation)
	{
		i = 0;
		while (i < shared->max_philos)
		{
			if (shared->meal_time_arr[i] <= get_lowest_meal_time(shared) && \
			shared->num_meals_arr[i] <= get_min_num_meal(shared) && \
			!shared->forks_arr[i].__data.__lock && \
			!shared->forks_arr[get_neighbor(i, \
			shared->max_philos)].__data.__lock)
			{
				shared->priority = i;
				break ;
			}
			++i;
		}
		usleep(500);
	}
	return (NULL);
}
