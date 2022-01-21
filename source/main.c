/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:36:08 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/19 20:00:28 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_digit(char **argv)
{
	int	i;
	int	j;
	int	len;

	len = get_tokens_len(argv);
	i = 1;
	while (i < len)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static int	check_negative(char **argv)
{
	int	i;
	int	len;

	len = get_tokens_len(argv);
	i = 1;
	while (i < len)
	{
		if (ft_atoi(argv[i]) < 0)
			return (0);
		++i;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_shared	*shared;

	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (!check_negative(argv) || !check_digit(argv))
	{
		printf("Error: bad arguments\n");
		return (1);
	}
	shared = ft_calloc(1, sizeof(t_shared));
	set_shared(shared, argv);
	init_mutex(shared);
	create_threads(shared);
	wait_threads(shared);
	destroy_mutex(shared);
	free_shared(shared);
	return (0);
}
