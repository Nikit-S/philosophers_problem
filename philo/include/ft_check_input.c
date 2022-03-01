/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:56:22 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:07:56 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_input(int argi, char *argc[])
{
	int	i;

	if (argi > 6 || argi < 5)
		return (0);
	while (argi > 1)
	{
		i = 0;
		if (ft_atoi(argc[argi - 1]) == 0)
			return (0);
		while (argc[argi - 1][i])
		{
			if (argc[argi - 1][i] < '0' || argc[argi - 1][i] > '9')
				return (0);
			i++;
		}
		argi--;
	}
	return (1);
}
