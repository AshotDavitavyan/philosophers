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

////////////////////////////////////////////DO GIT PUSH!!!!!!!!!!!!!!//////////////////////////////////////
//mutex die
//detach and join

#include "../includes/philo.h"

long long get_time(void)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL) == -1)
		write (2, "Error: GETTIMEOFDAY(2)\n", 28);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	mx_printf(char *to_print, t_philo *philo)
{
	long long	time;

	time = get_time() - philo->info->start;
	pthread_mutex_lock(&philo->info->mxprint);
	printf("%lld %d %s", time, philo->index, to_print);
	pthread_mutex_unlock(&philo->info->mxprint);
}

void	ft_usleep(int ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(ms / 10);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->f_next->mxfork));
	mx_printf("has taken a fork\n", philo);
	pthread_mutex_lock(&(philo->f_prev->mxfork));
	mx_printf("has taken a fork\n", philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mxate);
	philo->last_time_ate = get_time();
	philo->meals_count++;
	pthread_mutex_unlock(&philo->mxate);
	mx_printf("is eating\n", philo);
	ft_usleep(philo->info->time_to_eat);
	mx_printf("is sleeping\n", philo);
	ft_usleep(philo->info->time_to_sleep);
}

void	*routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->mxate);
	philo->last_time_ate = get_time();
	pthread_mutex_unlock(&philo->mxate);
	if (philo->index % 2 == 0)
		usleep(philo->info->time_to_die/2);
	pthread_mutex_lock(&philo->info->mxstop);
	while (philo->info->stop == 0)
	{
		pthread_mutex_unlock(&philo->info->mxstop);
		take_forks(philo);
		eat(philo);
		pthread_mutex_unlock(&(philo->f_next->mxfork));
		pthread_mutex_unlock(&(philo->f_prev->mxfork));
		pthread_mutex_lock(&philo->info->mxstop);
	}
	pthread_mutex_unlock(&philo->info->mxstop);
	return (NULL);
}

int meal_check(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philo->mxate);
	if (philo->info->num_of_meals == -1)
	{
		pthread_mutex_unlock(&philo->mxate);
		return (0);
	}
	pthread_mutex_unlock(&philo->mxate);
	while (philo->info->number_of_phil > i)
	{
		pthread_mutex_lock(&philo->mxate);
		if (philo->meals_count < philo->info->num_of_meals)
		{
			pthread_mutex_unlock(&philo->mxate);
			return (0);
		}
		pthread_mutex_unlock(&philo->mxate);
		philo = philo->next;
		i++;
	}
	return (1);
}

int	check_philos(t_philo *philos)
{
	int i;

	i = philos->info->number_of_phil;
	usleep(100);
	while (i > 0)
	{
		pthread_mutex_lock(&philos->mxate);
		if ((get_time() - philos->last_time_ate) > philos->info->time_to_die)
		{
			pthread_mutex_unlock(&philos->mxate);
			pthread_mutex_lock(&philos->info->mxstop);
			philos->info->stop = 1;
			pthread_mutex_unlock(&philos->info->mxstop);
			mx_printf("has died\n", philos);
			return (-1);
		}
		pthread_mutex_unlock(&philos->mxate);
		if (meal_check(philos))
		{
			pthread_mutex_lock(&philos->info->mxstop);
			philos->info->stop = 1;
			pthread_mutex_unlock(&philos->info->mxstop);
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
			break ;
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
	int		i;

	i = 0;
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
	init_threads(philos);
	return (0);
}