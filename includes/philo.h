#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "../libft/libft.h"

typedef pthread_mutex_t t_mutex;

typedef struct s_info
{
	int			number_of_phil;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_to_eat;
	int			die;
	long long	start;
	t_mutex		mxprint;
}				t_info;

typedef	struct s_fork
{
	int 			taken;
	t_mutex			mxfork;
}					t_fork;


typedef struct s_philo
{
	int				index;
	long long		last_time_ate;
	t_mutex			mxate;
	t_info			*info;
	int				lfork;
	int				rfork;
	struct s_fork	*f_next;
	struct s_fork	*f_prev;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_t		th;
}	t_philo;

int	isnum(char *arg);
int	check_args(int number_arg, char **args, char *save);

void	add_info(t_info *start_info, char **argv);
void	circle_list(t_philo *head);
void	add_forks(t_philo *philos);

t_philo	*create_philos(t_info *start_info);
t_philo	*philoadd_back(t_philo *to_add, t_philo *philo);
t_philo	*add_philo(int index, t_info *info);
#endif
