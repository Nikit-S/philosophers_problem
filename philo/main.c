/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:33:06 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:09:26 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static int	init_inp(t_inp *inp, char *argv[], int argi)
{
	if (!ft_check_input(argi, argv))
	{
		printf("input error\n");
		return (0);
	}
	inp->phil_n = ft_atoi(argv[1]);
	inp->time_d = ft_atoi(argv[2]);
	inp->time_e = ft_atoi(argv[3]);
	inp->time_s = ft_atoi(argv[4]);
	inp->allow_output = 1;
	if (argi == 6)
		inp->num_e = ft_atoi(argv[5]);
	else
		inp->num_e = -1;
	return (1);
}

static t_phill	*ft_init_table(t_inp *inp)
{
	t_phill	*phill;
	t_phill	*temp;
	t_phil	phil;
	int		i;

	i = 0;
	init_phil(&phil, 0, inp);
	phill = ft_lstnew_phill(phil);
	while (i < inp->phil_n - 1)
	{
		init_phil(&phil, i + 1, inp);
		ft_lstadd_back_phill(&phill, ft_lstnew_phill(phil));
		i++;
	}
	temp = ft_lstlast_phill(phill);
	temp->next = phill;
	temp->phil.l_fork = &(temp->next->phil.r_fork);
	return (phill);
}

static void	sim_cleaning(t_phill **philll)
{
	int		i;
	t_phill	*temp;
	t_phill	*phill;

	i = 0;
	phill = *philll;
	while (i < phill->phil.knl->phil_n)
	{
		temp = phill;
		pthread_join(temp->phil.thread, NULL);
		phill = phill->next;
		i++;
	}
	while (i != 0)
	{
		temp = phill;
		phill = phill->next;
		pthread_mutex_destroy(&(temp->phil.r_fork));
		free(temp);
		i--;
	}
}

static void	sim(t_phill **phill)
{
	int	i;
	int	l;

	l = (*phill)->phil.knl->phil_n;
	i = 0;
	while (i < l)
	{
		pthread_create(&((*phill)->phil.thread),
			NULL, ft_take_forks, &((*phill)->phil));
		*phill = (*phill)->next;
		i++;
		usleep(500);
	}
	i = 1;
	while (i)
	{
		usleep(500);
		ft_lstiter_phill(*phill, ft_changedead, (*phill)->phil.knl);
		if (!ft_checkdead(*phill) || ft_checksatiety(*phill,
				(*phill)->phil.knl))
			i = 0;
	}
	sim_cleaning(phill);
}

int	main(int argi, char *argv[])
{
	t_phill			*phill;
	struct timeval	start_time;
	t_inp			inp;

	if (!init_inp(&inp, argv, argi))
		return (0);
	phill = ft_init_table(&inp);
	gettimeofday(&start_time, NULL);
	printf("%ld start\n", start_time.tv_sec * 1000
		+ start_time.tv_usec / 1000);
	ft_lstiter_phill(phill, ft_lm_time, &start_time);
	sim(&phill);
	return (0);
}
