/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:49:27 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/22 17:49:28 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_info
{
	int			num_of_phil;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_meals;
	long long	start;
	sem_t		*s_forks;
	sem_t		*s_print;
}				t_info;

typedef struct s_philo
{
	int				index;
	int				meals_count;
	int				death;
	long long		last_time_ate;
	t_info			*info;
	sem_t			*s_eat_count;
	sem_t			*s_eat_time;
	pthread_t		checker;
}	t_philo;

void		add_info(t_info *start_info, char **argv);
void		ft_usleep(int ms);
void		init_sems(t_info *info);
void		print_sem(char *to_print, t_philo *philo);
void		make_philos(t_info *info, t_philo *philos);
void		philo_life(t_philo *philo);

int			isnum(char *arg);
int			check_args(int number_arg, char **args, char *save);

long long	get_time(void);

#endif
