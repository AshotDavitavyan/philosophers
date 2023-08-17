/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:55:08 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/17 18:55:15 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "../libft/libft.h"

typedef pthread_mutex_t	t_mutex;

typedef struct s_info
{
	int			number_of_phil;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_meals;
	int			stop;
	long long	start;
	t_mutex		mxprint;
	t_mutex		mxstop;
}				t_info;

typedef struct s_fork
{
	t_mutex			mxfork;
}					t_fork;

typedef struct s_philo
{
	int				index;
	int				meals_count;
	int				death;
	long long		last_time_ate;
	t_mutex			mxate;
	t_mutex			mxdeath;
	t_info			*info;
	struct s_fork	*f_next;
	struct s_fork	*f_prev;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_t		th;
}	t_philo;

int			isnum(char *arg);
int			check_args(int number_arg, char **args, char *save);
int			init_threads(t_philo *philos);

long long	get_time(void);

void		*routine(void *ptr);
void		ft_usleep(int ms);
void		mx_printf(char *to_print, t_philo *philo);
void		add_info(t_info *start_info, char **argv);
void		circle_list(t_philo *head);
void		add_forks(t_philo *philos);

t_philo		*create_philos(t_info *start_info);
t_philo		*philoadd_back(t_philo *to_add, t_philo *philo);
t_philo		*add_philo(int index, t_info *info);
#endif
