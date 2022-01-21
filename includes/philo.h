/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:16:08 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/21 03:17:03 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define LEFT_PHILO 0
# define RIGHT_PHILO 1
# define TAKEN_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DEAD 5
# define FULL 6
# define PRINT_TAKEN_FORK "has taken a fork"
# define PRINT_EATING "is eating"
# define PRINT_SLEEPING "is sleeping"
# define PRINT_THINKING "is thinking"
# define PRINT_DEATH "died"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_shared {
	long int			start_time;
	int					philos_num;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	int					max_meals;
	int					*num_meals_arr;
	long int			*meal_time_arr;
	int					*satisfied_arr;
	int					stop_simulation;
	int					printed_death;
	pthread_t			*philos_arr;
	pthread_t			dead_philo_th;
	pthread_t			full_philo_th;
	pthread_mutex_t		*forks_arr;
	pthread_mutex_t		print_mutex;
}t_shared;

typedef struct s_philo {
	int			id;
	int			index;
	int			status;
	int			delay;
	t_shared	*shared;
}t_philo;

					/*
					* MANAGE_PHILOSOPHERS
					*/

void		create_threads(t_shared *shared);
void		wait_threads(t_shared *shared);
void		init_mutex(t_shared *shared);
void		destroy_mutex(t_shared *shared);

					/*
					* ROUTINE
					*/

void		*routine(void *args);
void		*get_dead_philo(void *args);
void		*get_full_philo(void *args);
int			locking_forks(t_philo *info, int *neighbors);
void		unlocking_forks(t_philo *info, int *neighbors);
long int	get_clock(long int start_time);
void		set_neighbors(t_philo *info, int *neighbors);

					/*
					* UTILS
					*/

int			ft_atoi(const char *nptr);
long int	ft_atoli(const char *nptr);
int			ft_isdigit(int c);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_strcmp(const char *s1, const char *s2);
void		set_shared(t_shared *shared, char **argv);
void		free_shared(t_shared *shared);
int			get_tokens_len(char **tokens);
int			print_status(t_shared *shared, int id, \
char *print_status, int times);
int			stop_philo(t_shared *shared, int index);
#endif