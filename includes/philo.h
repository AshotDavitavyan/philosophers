#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "../libft/libft.h"

typedef struct s_info
{
	int	number_of_phil;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_to_eat;
}		t_info;

typedef struct s_philo
{
	int		fork_left;
	int		fork_rigjt;
	t_info	*info;
	t_philo	*next;
	t_philo	*prev;
}	t_philo;
#endif
