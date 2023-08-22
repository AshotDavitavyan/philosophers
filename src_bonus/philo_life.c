/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:26:25 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/22 16:26:27 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*checker(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		sem_wait(philo->s_eat);
		if (get_time() - philo->last_time_ate >= philo->info->time_to_die)
		{
			sem_post(philo->s_eat);
			sem_wait(philo->info->s_print);
			printf("%lld %d has died\n", \
			get_time() - philo->info->start, philo->index);
			exit(1);
		}
		else if (philo->meals_count == philo->info->num_of_meals)
		{
			sem_post(philo->s_eat);
			sem_wait(philo->info->s_print);
			exit(0);
		}
		sem_post(philo->s_eat);
	}
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->info->s_forks);
	print_sem("has taken a fork", philo);
	sem_wait(philo->info->s_forks);
	print_sem("has taken a fork", philo);
}

void	eat(t_philo *philo)
{
	print_sem("is eating", philo);
	sem_wait(philo->s_eat);
	philo->meals_count++;
	philo->last_time_ate = get_time();
	sem_post(philo->s_eat);
	ft_usleep(philo->info->time_to_eat);
	sem_post(philo->info->s_forks);
	sem_post(philo->info->s_forks);
	print_sem("is sleeping", philo);
	ft_usleep(philo->info->time_to_sleep);
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
