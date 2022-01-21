/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:57:45 by fbafica           #+#    #+#             */
/*   Updated: 2022/01/19 14:01:17 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = '\0';
		++ptr;
		--n;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return ((void *)p);
}
