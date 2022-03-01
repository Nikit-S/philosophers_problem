/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksatiety.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:33:32 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:45:51 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_checksatiety(t_phill *phill, t_inp *inp)
{
	t_phill	*start;
	int		cmp;

	start = phill;
	cmp = phill->phil.nu;
	if (inp->num_e == -1)
		return (0);
	while (start->next->phil.nu != cmp)
	{
		if (start->phil.meals < inp->num_e)
			return (0);
		start = start->next;
	}
	if (start->phil.meals < inp->num_e)
		return (0);
	inp->allow_output = 0;
	usleep(10000);
	printf("all philosophers ate %i meals\n", inp->num_e);
	return (1);
}
