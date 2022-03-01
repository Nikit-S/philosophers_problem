/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changedead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:33:24 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_changedead(void *phil, void *arg)
{
	struct timeval	start_time;
	struct timeval	dif;

	gettimeofday(&start_time, NULL);
	dif.tv_sec = ((t_inp *)arg)->time_d / 1000;
	dif.tv_usec = (((t_inp *)arg)->time_d - (((t_inp *)arg)->time_d
				/ 1000 * 1000)) *1000;
	start_time = ft_time_diff(start_time, ((t_phil *)phil)->last_meal);
	if (ft_time_cmp(start_time, dif) == 1
		&& ((t_phil *)phil)->eat == 0)
	{
		((t_phil *)phil)->alive = 0;
		((t_inp *)arg)->allow_output = 0;
	}
}
