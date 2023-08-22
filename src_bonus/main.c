/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:25:41 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/22 16:25:41 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	*start_info;
	t_philo	*philos;

	if (check_args(argc, argv, *argv) == 0)
	{
		system("leaks philo");
		return (1);
	}
	start_info = (t_info *)malloc(sizeof(t_info));
	philos = NULL;
	add_info(start_info, argv);
	make_philos(start_info, philos);
	return (0);
}
