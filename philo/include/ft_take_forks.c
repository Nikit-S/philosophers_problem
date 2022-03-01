/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:34:20 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	lock_forks(t_phil *phil)
{
	if (phil->knl->phil_n == 1)
		return (0);
	if (phil->nu % 2 == 0)
	{
		pthread_mutex_lock(phil->l_fork);
		pthread_mutex_lock(&(phil->r_fork));
	}
	else
	{
		pthread_mutex_lock(&(phil->r_fork));
		pthread_mutex_lock(phil->l_fork);
	}
	return (1);
}

void	*ft_take_forks(void *arg)
{
	t_phil			*phil;
	struct timeval	start_time;

	phil = (t_phil *)arg;
	if (phil->nu % 2 == 0)
		usleep(500);
	while (phil->knl->allow_output)
	{
		if (phil->think && lock_forks(phil))
		{
			phil->tk_forks = 0;
			phil->think = 0;
			gettimeofday(&start_time, NULL);
			if (phil->knl->allow_output)
				printf("%ld %i has taken a fork\n", start_time.tv_sec * 1000
					+ start_time.tv_usec / 1000, phil->nu + 1);
			if (phil->knl->allow_output)
				ft_eating(phil);
		}
	}
	return (NULL);
}
