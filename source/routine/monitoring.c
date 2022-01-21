/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:20:21 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/20 20:51:45 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*get_full_philo(void *args)
{
	t_shared	*shared;
	int			satisfied_philos;
	int			i;

	shared = (t_shared *)args;
	satisfied_philos = 0;
	while (!shared->stop_simulation && shared->max_meals && \
	satisfied_philos < shared->philos_num)
	{
		usleep(1 * 1000);
		i = 0;
		while (!shared->stop_simulation && i < shared->philos_num)
		{
			if (shared->satisfied_arr[i] != FULL && \
			shared->num_meals_arr[i] >= shared->max_meals)
			{
				shared->satisfied_arr[i] = FULL;
				++satisfied_philos;
			}
			++i;
		}
	}
	if (satisfied_philos >= shared->philos_num)
		shared->stop_simulation = 1;
	return (NULL);
}

void	*get_dead_philo(void *args)
{
	t_shared	*shared;
	long int	time;
	int			i;

	shared = (t_shared *)args;
	while (!shared->stop_simulation)
	{
		usleep(1 * 1000);
		i = 0;
		while (i < shared->philos_num && !shared->stop_simulation)
		{
			time = get_clock(shared->start_time);
			if (time - shared->meal_time_arr[i] > shared->time_to_die)
			{
				shared->stop_simulation = 1;
				printf("%6ld  %6d  %s\n", time, i + 1, PRINT_DEATH);
				break ;
			}
			++i;
		}
	}
	return (NULL);
}
