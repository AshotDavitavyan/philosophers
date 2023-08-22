
#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include "../libft/libft.h"

typedef struct s_info
{
	int			num_of_phil;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_meals;
	int			stop;
	long long	start;
	sem_t		*forks;
	sem_t		*print;
}				t_info;

typedef struct s_philo
{
	int				index;
	int				meals_count;
	int				death;
	long long		last_time_ate;
	t_info			*info;
	sem_t			*eat;
	pthread_t		checker;
}	t_philo;

void	add_info(t_info *start_info, char **argv);
void	ft_usleep(int ms);

int	isnum(char *arg);
int	check_args(int number_arg, char **args, char *save);

long long	get_time(void);

#endif