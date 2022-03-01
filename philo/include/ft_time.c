/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:34:25 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

struct timeval	ft_time_diff(struct timeval a, struct timeval b)
{
	struct timeval	ret;

	ret.tv_sec = a.tv_sec - b.tv_sec;
	ret.tv_usec = a.tv_usec - b.tv_usec;
	if (ret.tv_usec < 0)
		ret.tv_sec--;
	if (ret.tv_usec < 0)
		ret.tv_usec += 1000000;
	return (ret);
}

int	ft_time_cmp(struct timeval a, struct timeval b)
{
	if (a.tv_sec > b.tv_sec)
		return (1);
	else if (a.tv_sec < b.tv_sec)
		return (-1);
	else
	{
		if (a.tv_usec > b.tv_usec)
			return (1);
		else if (a.tv_usec < b.tv_usec)
			return (-1);
		else
			return (0);
	}
}
