/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_phill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:36:43 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lstiter_phill(t_phill *lst, void (*f)(void *, void*), void *arg)
{
	t_phill	*start;
	int		cmp;

	start = lst;
	cmp = start->phil.nu;
	while (start->next->phil.nu != cmp)
	{
		f(&(start->phil), arg);
		start = start->next;
	}
	f(&(start->phil), arg);
}

void	*ft_fre(void *a, void *arg)
{
	(void) arg;
	free (a);
	return (NULL);
}
