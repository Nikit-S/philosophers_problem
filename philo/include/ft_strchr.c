/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:01:19 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*pt;

	if (!s)
		return (NULL);
	pt = (char *)s;
	i = 0;
	while (pt[i])
	{
		if (pt[i] == c)
			return (&pt[i]);
		i++;
	}
	if (pt[i] == c)
		return (&pt[i]);
	return (NULL);
}
