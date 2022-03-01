/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:33:36 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	drop_forks(t_phil *phil)
{
	if (phil->nu % 2)
	{
		pthread_mutex_unlock(phil->l_fork);
		pthread_mutex_unlock(&(phil->r_fork));
	}
	else
	{
		pthread_mutex_unlock(&(phil->r_fork));
		pthread_mutex_unlock(phil->l_fork);
	}
}

void	*ft_eating(void *arg)
{
	struct timeval	start_time;
	t_phil			*phil;

	phil = (t_phil *)arg;
	gettimeofday(&start_time, NULL);
	phil->eat = 1;
	if (phil->knl->allow_output)
		printf("%ld %i is eating\n", start_time.tv_sec * 1000
			+ start_time.tv_usec / 1000,
			phil->nu + 1);
	if (!phil->knl->allow_output)
		return (NULL);
	usleep(phil->knl->time_e * 1000);
	gettimeofday(&start_time, NULL);
	phil->last_meal = start_time;
	drop_forks(phil);
	phil->meals++;
	phil->eat = 0;
	ft_sleeping(phil);
	return (NULL);
}
