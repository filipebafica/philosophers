/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dead_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:20:21 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/24 15:39:10 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		while (i < shared->max_philos)
		{
			time = get_clock(shared->start_time);
			if (time - shared->meal_time_arr[i] > shared->time_to_die && \
			shared->satisfied_arr[i] != FULL)
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
