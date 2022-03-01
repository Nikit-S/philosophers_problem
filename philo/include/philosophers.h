/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 12:34:37 by barcher           #+#    #+#             */
/*   Updated: 2021/07/04 17:42:35 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct s_inp
{
	int		phil_n;
	sem_t	*forks_s;
	int		time_d;
	int		time_e;
	int		time_s;
	int		num_e;
	int		allow_output;

}	t_inp;

typedef struct s_phil
{
	int				nu;
	int				alive;
	struct timeval	last_meal;
	int				think;
	int				eat;
	int				tk_forks;
	int				meals;
	t_inp			*knl;
	pthread_t		thread;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}	t_phil;

typedef struct s_phill
{
	t_phil			phil;
	struct s_phill	*next;
}	t_phill;

char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *nptr);
int				ft_check_input(int argi, char *argc[]);
int				ft_checkdead(t_phill *lst);
int				ft_checksatiety(t_phill *phill, t_inp *inp);
int				ft_forks(t_inp *inp);
int				ft_time_cmp(struct timeval a, struct timeval b);
size_t			ft_strlen(const char *s);
struct timeval	ft_time_diff(struct timeval a, struct timeval b);
t_phill			*ft_lst_nu(t_phill *phill, int nu);
t_phill			*ft_lstlast_phill(t_phill *lst);
t_phill			*ft_lstnew_phill(t_phil phil);
void			*ft_eating(void *arg);
void			*ft_sleeping(void *arg);
void			*ft_take_forks(void *arg);
void			ft_changedead(void *phil, void *arg);
void			ft_destroy_mutex(void *phil, void *arg);
void			ft_lm_time(void *phil, void *time);
void			ft_lstadd_back_phill(t_phill **lst, t_phill *new);
void			ft_lstiter_phill(t_phill *lst,
					void (*f)(void *, void *), void *arg);
void			ft_mutex_lst_dest(t_phill *phill, int nu);
void			ft_ps(t_phil *phil);
void			init_phil(t_phil *phil, int nu, t_inp *inp);
#endif
