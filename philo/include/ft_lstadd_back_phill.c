/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_phill.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:52:59 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lstadd_back_phill(t_phill **lst, t_phill *new)
{
	t_phill	*ret;

	ret = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		ret = ft_lstlast_phill(*lst);
		ret->next = new;
		ret->phil.l_fork = &(ret->next->phil.r_fork);
	}
}
