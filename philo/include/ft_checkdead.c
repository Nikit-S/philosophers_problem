/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:33:28 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_checkdead(t_phill *lst)
{
	t_phill			*start;
	int				cmp;
	struct timeval	start_time;

	start = lst;
	cmp = start->phil.nu;
	while (start->next->phil.nu != cmp)
	{
		if (!start->phil.alive)
		{
			gettimeofday(&start_time, NULL);
			printf("%ld %i died\n", start_time.tv_sec * 1000
				+ start_time.tv_usec / 1000, start->phil.nu + 1);
			return (0);
		}
		start = start->next;
	}
	if (!start->phil.alive)
	{
		gettimeofday(&start_time, NULL);
		printf("%ld %i died\n", start_time.tv_sec * 1000
			+ start_time.tv_usec / 1000, start->phil.nu + 1);
		return (0);
	}
	return (1);
}
