/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:33:48 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_mutex_lst_dest(t_phill *phill, int nu)
{
	t_phill	*temp;
	int		i;

	i = 0;
	temp = phill;
	while (i < nu)
	{
		pthread_mutex_destroy(&(temp->phil.r_fork));
		temp = temp->next;
		i++;
	}
}
