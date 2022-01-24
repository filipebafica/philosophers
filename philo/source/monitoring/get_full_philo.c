/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:20:21 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/23 17:02:34 by fbafica          ###   ########.fr       */
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
	satisfied_philos < shared->max_philos)
	{
		usleep(1 * 1000);
		i = 0;
		while (i < shared->max_philos)
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
	if (satisfied_philos >= shared->max_philos)
		shared->stop_simulation = 1;
	return (NULL);
}
