/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:37:15 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/19 11:37:34 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return ('\0' - s2[i]);
	if (!s2)
		return (s1[i] - '\0');
	while (s1[i] == s2[i] && s1[i] != '\0')
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
