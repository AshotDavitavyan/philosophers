/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:55:47 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/17 18:56:00 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	meal_check(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->info->num_of_meals == -1)
		return (0);
	while (philo->info->number_of_phil > i)
	{
		pthread_mutex_lock(&(philo->mxate));
		if (philo->meals_count < philo->info->num_of_meals)
		{
			pthread_mutex_unlock(&(philo->mxate));
			return (0);
		}
		pthread_mutex_unlock(&(philo->mxate));
		philo = philo->next;
		i++;
	}
	pthread_mutex_lock(&(philo->info->mxstop));
	philo->info->stop = 1;
	pthread_mutex_unlock(&(philo->info->mxstop));
	return (1);
}

int	check_philos(t_philo *philos, int i)
{
	usleep(100);
	while (i > 0)
	{
		pthread_mutex_lock(&(philos->mxate));
		if ((get_time() - philos->last_time_ate) > philos->info->time_to_die)
		{
			pthread_mutex_unlock(&(philos->mxate));
			pthread_mutex_lock(&(philos->info->mxstop));
			philos->info->stop = 1;
			pthread_mutex_unlock(&(philos->info->mxstop));
			pthread_mutex_lock(&(philos->mxdeath));
			philos->death = 1;
			pthread_mutex_unlock(&(philos->mxdeath));
			mx_printf("has died\n", philos);
			return (-1);
		}
		pthread_mutex_unlock(&(philos->mxate));
		if (meal_check(philos))
			return (-1);
		i--;
		philos = philos->next;
	}
	return (0);
}

int	init_threads(t_philo *philos)
{
	int	i;

	i = philos->info->number_of_phil;
	while (i > 0)
	{
		pthread_create(&philos->th, NULL, routine, philos);
		i--;
		philos = philos->next;
	}
	while (1)
	{
		if (check_philos(philos, philos->info->number_of_phil) == (-1))
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
