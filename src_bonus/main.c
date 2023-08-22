#include "../includes/philo_bonus.h"

void	init_sems(t_info *info, t_philo *philo)
{
	sem_unlink("forks");
	info->forks = sem_open("forks", O_CREAT, 0644, info->num_of_phil);
	sem_unlink("print");
	info->print = sem_open("print", O_CREAT, 0644, 1);
	sem_unlink("eat");
	philo->eat = sem_open("eat", O_CREAT, 0644, 1);
}

void	print_sem(char *to_print, t_philo *philo)
{
	long long	time;

	time = (get_time() - philo->info->start);
	sem_wait(philo->info->print);
	printf("%lld %d %s\n", time, philo->index, to_print);
	sem_post(philo->info->print);
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->info->forks);
	print_sem("has taken a fork\n", philo);
	sem_wait(philo->info->forks);
	print_sem("has taken a fork\n", philo);
}

void	eat(t_philo *philo)
{
	sem_wait(philo->eat);
	print_sem("is eating\n", philo);
	philo->meals_count++;
	philo->last_time_ate = get_time();
	ft_usleep(philo->info->time_to_eat);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	print_sem("is sleeping\n", philo);
	ft_usleep(philo->info->time_to_sleep);
	sem_post(philo->eat);
}

void	*checker(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	
}

void	philo_life(t_philo *philo)
{
	pthread_create(&philo->checker, NULL, checker, philo);
	while (1)
	{
		take_forks(philo);
		eat(philo);
	}
}

void	launch_philos(t_philo *philos, t_info *info)
{
	int 	i;
	pid_t	*pid;

	i = 0;
	pid = (pid_t *)malloc(sizeof(pid_t) * info->num_of_phil);
	printf("bus\n");
	while (info->num_of_phil > i)
	{
		pid[i] = fork();
		philos[i].last_time_ate = get_time();
		philos[i].index = i + 1;
		philos[i].info = info;
		if (pid[i] == 0)
			philo_life(&philos[i]);
		i++;
	}
}

void	make_philos(t_info *info, t_philo *philos)
{
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_phil);
	init_sems(info);
	launch_philos(philos, info);
}

int	main(int argc, char **argv)
{
	t_info	*start_info;
	t_philo	*philos;

	if (argc == 2 && ft_strnstr(argv[1], "order", 5) != NULL)
	{
		printf("<philosophers> <time to die> <time to eat>\
		<time to sleep> <times each philosopher must eat>\n");
		return (0);
	}
	if (check_args(argc, argv, *argv) == 0)
		return (1);
	start_info = (t_info *)malloc(sizeof(t_info));
	philos = NULL;
	add_info(start_info, argv);
	make_philos(start_info, philos);
	return (0);
}