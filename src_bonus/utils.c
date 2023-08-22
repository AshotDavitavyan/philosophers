/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:26:13 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/22 17:54:29 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write (2, "Error: GETTIMEOFDAY(2)\n", 28);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(ms / 10);
}

void	init_sems(t_info *info)
{
	sem_unlink("forks");
	info->s_forks = sem_open("forks", O_CREAT, 0644, info->num_of_phil);
	sem_unlink("print");
	info->s_print = sem_open("print", O_CREAT, 0644, 1);
}

void	print_sem(char *to_print, t_philo *philo)
{
	long long	time;

	time = (get_time() - philo->info->start);
	sem_wait(philo->info->s_print);
	printf("%lld %d %s\n", time, philo->index, to_print);
	sem_post(philo->info->s_print);
}
