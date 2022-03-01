/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:34:31 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_ps(t_phil *phil)
{
	printf("N%i_A%i_LMS%li_LMUS%li_TH%i_E%i_M%i_LF%p_RF%p\n",
		phil->nu, phil->alive, phil->last_meal.tv_sec,
		phil->last_meal.tv_usec, phil->think, phil->eat,
		phil->meals, phil->l_fork,
		&(phil->r_fork));
}
