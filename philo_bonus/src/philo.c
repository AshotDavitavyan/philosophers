/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:26:04 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/22 17:49:04 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	end_stuff(pid_t *pid, t_philo *philos)
{
	free(philos);
	free(pid);
}

void	launch_philos(t_philo *philos, t_info *info, int i)
{
	pid_t	*pid;
	int		exit_status;

	pid = (pid_t *)malloc(sizeof(pid_t) * info->num_of_phil);
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
	waitpid(-1, &exit_status, 0);
	if (exit_status / 256 == 1 || exit_status / 256 == 0)
	{
		while (--i >= 0)
			kill(pid[i], SIGKILL);
	}
	end_stuff(pid, philos);
}

void	make_philos(t_info *info, t_philo *philos)
{
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_phil);
	init_sems(info);
	launch_philos(philos, info, 0);
}
