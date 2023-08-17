/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:26:10 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/17 18:58:31 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	*start_info;
	t_philo	*philos;

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
