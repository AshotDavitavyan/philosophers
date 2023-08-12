/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:26:10 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/11 19:10:19 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//make printf_mut

#include "../includes/philo.h"

void	ft_usleep(int ms)
{
	struct timeval start;
	struct timeval now;
	
	gettimeofday(&start, 0);
	gettimeofday(&now, 0);
	while ((now.tv_sec + now.tv_usec) - (start.tv_sec + start.tv_usec) < ms)
		usleep(10);
}

long long get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write (2, "Error: GETTIMEOFDAY(2)\n", 28);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	take_forks_util(t_philo *philo, int which)
{
	if (which == 1)
	{
		pthread_mutex_lock(&philo->f_next->mx);
		printf("%d has taken a fork\n", philo->index);
		philo->f_next->taken = 1;
		philo->rfork = 1;
		pthread_mutex_unlock(&philo->f_next->mx);
	}
	else if (which == (-1))
	{
		pthread_mutex_lock(&philo->f_prev->mx);
		printf("%d has taken a fork\n", philo->index);
		philo->f_prev->taken = 1;
		philo->lfork = 1;
		pthread_mutex_unlock(&philo->f_prev->mx);
	}
}

void	take_forks(t_philo *philo, int which)
{
	if (which == 2)
	{
		take_forks_util(philo, 1);
		take_forks_util(philo, (-1));
	}
	else if (which == 1)
		take_forks_util(philo, 1);
	else if (which == -1)
		take_forks_util(philo, -1);
}

void	*routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	philo->last_time_ate = get_time();
	if (philo->index % 2 == 0)
		usleep(2000);
	while (1)
	{
		take_forks(philo, 2);
		if (philo->lfork == 1 && philo->rfork == 1)
		{
			philo->last_time_ate = get_time();
			printf("%lld %d is eating\n", philo->last_time_ate, philo->index);
			ft_usleep(philo->info->time_to_eat);
			printf("%lld %d is sleeping\n", get_time(), philo->index);
			ft_usleep(philo->info->time_to_sleep);
		}
	}
	return (NULL);
}


int	check_philos(t_philo *philos)
{
	int i;

	i = philos->info->number_of_phil;
	while (i > 0)
	{
		if (get_time() - philos->last_time_ate >= philos->info->time_to_die)
		{
			printf("%lld %d has died\n", get_time(), philos->index);
			return (-1);
		}
		i--;
		philos = philos->next;
	}
	return (0);
}

int	init_threads(t_philo *philos)
{
	int i;

	i = philos->info->number_of_phil;
	while (i > 0)
	{
		pthread_create(&philos->th, NULL, routine, philos);
		i--;
		philos = philos->next;
	}
	while (1)
	{
		if (check_philos(philos) == (-1))
			return (-1);
	}
	while (i < philos->info->number_of_phil)
	{
		i++;
		pthread_join(philos->th, NULL);
		philos = philos->next;
	}
	return (0);
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
 	add_info(start_info, argv);
 	philos = create_philos(start_info);
 	add_forks(philos);
	if(init_threads(philos) == -1)
		return (1);
	return (0);
}