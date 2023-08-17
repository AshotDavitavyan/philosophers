/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:58:03 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/17 18:58:04 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
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
	pthread_mutex_lock(&(philo->info->mxprint));
	pthread_mutex_lock(&(philo->mxdeath));
	pthread_mutex_lock(&(philo->info->mxstop));
	if (philo->info->stop == 0)
		printf("%lld %d %s", time, philo->index, to_print);
	else if (philo->death == 1)
	{
		philo->death = 0;
		printf("%lld %d %s", time, philo->index, to_print);
	}
	pthread_mutex_unlock(&(philo->mxdeath));
	pthread_mutex_unlock(&(philo->info->mxstop));
	pthread_mutex_unlock(&philo->info->mxprint);
}

void	ft_usleep(int ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(ms / 10);
}
