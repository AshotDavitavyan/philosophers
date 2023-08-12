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

#include "../includes/philo.h"

void	take_forks(t_philo *philo, int which)
{
	if (which == 2)
	{
		printf("%d has taken a fork\n", philo->index);
		philo->f_next->taken = 1;
		printf("%d has taken a fork\n", philo->index);
		philo->f_prev->taken = 1;
	}
	else if (which == 1)
	{
		printf("%d has taken a fork\n", philo->index);
		philo->f_next->taken = 1;
	}
	else if (which == -1)
	{
		printf("%d has taken a fork\n", philo->index);
		philo->f_prev->taken = 1;
	}
}

void	*routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->info->even == 1)
	{
		
	}
	return (NULL);
}

long long get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write (2, "Error: GETTIMEOFDAY(2)\n", 28);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	check_philos(t_philo *philos)
{
	int i;

	i = philos->info->number_of_phil;
	while (i > 0)
	{
		if (get_time() - philos->last_time_ate >= philos->info->time_to_die)
		{
			printf("%ld %d has died\n", get_time(), philos->index);
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
		if (check_philos(philos) == -1)
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

void	add_forks(t_philo *philos)
{
	t_fork	*fork;

	while (philos->next->index > philos->index)
	{
		fork = (t_fork *)malloc(sizeof(t_fork));
		fork->taken = 0;
		philos->f_next = fork;
		philos->next->f_prev = fork;
		philos = philos->next;
	}
	fork = (t_fork *)malloc(sizeof(t_fork));
	fork->taken = 0;
	philos->f_next = fork;
	philos->next->f_prev = fork;
}

 int	main(int argc, char **argv)
 {
 	t_info	*start_info;
 	t_philo	*philos;

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

