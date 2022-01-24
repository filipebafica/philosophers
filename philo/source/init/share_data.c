/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:52:31 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/23 21:59:41 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_arr(t_shared *shared)
{
	int	i;

	i = 0;
	while (i < shared->max_philos)
	{
		shared->philos_arr[i] = i;
		shared->satisfied_arr[i] = 0;
		shared->meal_time_arr[i] = (long int) 0;
		shared->num_meals_arr[i] = 0;
		++i;
	}
}

void	set_shared(t_shared *shared, char **argv)
{
	shared->stop_simulation = 0;
	shared->priority = 0;
	shared->max_philos = ft_atoli(argv[1]);
	shared->time_to_die = ft_atoli(argv[2]);
	shared->time_to_eat = ft_atoli(argv[3]);
	shared->time_to_sleep = ft_atoli(argv[4]);
	shared->max_meals = 0;
	if (get_tokens_len(argv) > 5)
		shared->max_meals = ft_atoi(argv[5]);
	shared->num_meals_arr = malloc(sizeof(int) * shared->max_philos);
	shared->meal_time_arr = malloc(sizeof(long int) * shared->max_philos);
	shared->satisfied_arr = malloc(sizeof(int) * shared->max_philos);
	shared->forks_arr = malloc(sizeof(pthread_mutex_t) * shared->max_philos);
	shared->philos_arr = malloc(sizeof(pthread_t) * shared->max_philos);
	init_arr(shared);
}

void	free_shared(t_shared *shared)
{
	free(shared->num_meals_arr);
	free(shared->meal_time_arr);
	free(shared->satisfied_arr);
	free(shared->forks_arr);
	free(shared->philos_arr);
	free(shared);
}
