/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_phill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:30:19 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_phill	*ft_lstnew_phill(t_phil phil)
{
	t_phill	*ret;

	ret = (t_phill *)malloc(sizeof(t_phill));
	if (!ret)
		return (NULL);
	ret->phil = phil;
	ret->next = NULL;
	return (ret);
}
