/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:20:37 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/20 17:14:44 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_philo(t_shared *shared, int index)
{
	if (shared->stop_simulation != 0 || shared->satisfied_arr[index] == FULL)
		return (1);
	return (0);
}

int	print_status(t_shared *shared, int id, char *print_status, int times)
{
	usleep(id * 500);
	if (!shared->print_mutex.__data.__lock && !shared->stop_simulation)
	{
		pthread_mutex_lock(&shared->print_mutex);
		while (times > 0)
		{
			printf("%6ld  %6d  %s\n", \
			get_clock(shared->start_time), id, print_status);
			--times;
		}
		pthread_mutex_unlock(&shared->print_mutex);
		return (1);
	}
	return (0);
}
