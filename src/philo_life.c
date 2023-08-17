/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:57:47 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/17 18:57:48 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->f_next->mxfork));
	mx_printf("has taken a fork\n", philo);
	if (philo->info->number_of_phil == 1)
	{
		ft_usleep(philo->info->time_to_die);
		return ;
	}
	pthread_mutex_lock(&(philo->f_prev->mxfork));
	mx_printf("has taken a fork\n", philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mxate);
	philo->last_time_ate = get_time();
	mx_printf("is eating\n", philo);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->mxate);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&(philo->f_next->mxfork));
	pthread_mutex_unlock(&(philo->f_prev->mxfork));
	mx_printf("is sleeping\n", philo);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->mxate);
	philo->last_time_ate = get_time();
	pthread_mutex_unlock(&philo->mxate);
	if (philo->index % 2 == 0)
		usleep(philo->info->time_to_die / 2);
	pthread_mutex_lock(&(philo->info->mxstop));
	while (philo->info->stop == 0)
	{
		pthread_mutex_unlock(&(philo->info->mxstop));
		take_forks(philo);
		if (philo->info->number_of_phil == 1)
		{
			pthread_mutex_lock(&(philo->info->mxstop));
			break ;
		}
		eat(philo);
		ft_usleep(philo->info->time_to_sleep);
		pthread_mutex_lock(&(philo->info->mxstop));
	}
	pthread_mutex_unlock(&(philo->info->mxstop));
	return (NULL);
}
