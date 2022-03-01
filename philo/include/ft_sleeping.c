/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:34:11 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_sleeping(void *arg)
{
	struct timeval	start_time;
	t_phil			*phil;

	phil = (t_phil *)arg;
	gettimeofday(&start_time, NULL);
	if (phil->knl->allow_output)
		printf("%ld %i is sleeping\n", start_time.tv_sec * 1000
			+ start_time.tv_usec / 1000,
			phil->nu + 1);
	if (!phil->knl->allow_output)
		return (NULL);
	usleep(phil->knl->time_s * 1000);
	gettimeofday(&start_time, NULL);
	if (phil->knl->allow_output)
		printf("%ld %i is thinking\n", start_time.tv_sec * 1000
			+ start_time.tv_usec / 1000,
			phil->nu + 1);
	phil->think = 1;
	return (NULL);
}
