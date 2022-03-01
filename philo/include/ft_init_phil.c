/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_phil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:33:44 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_phil(t_phil *phil, int nu, t_inp *inp)
{
	phil->nu = nu;
	phil->alive = 1;
	phil->last_meal.tv_sec = 0;
	phil->last_meal.tv_usec = 0;
	phil->eat = 0;
	phil->think = 1;
	phil->tk_forks = 0;
	phil->meals = 0;
	phil->knl = inp;
	pthread_mutex_init(&(phil->r_fork), NULL);
	phil->l_fork = NULL;
}
