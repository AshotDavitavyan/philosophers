/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:26:10 by adavitav          #+#    #+#             */
/*   Updated: 2023/08/01 14:49:53 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	isnum(char *arg)
{
	if (*arg == '-')
	{
		ft_putstr_fd("Argument Should be Positive\n", 2);
		return (0);
	}
	if (*arg == '+')
	{
		while(*arg == '+')
		arg++;
	}
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
		{
			ft_putstr_fd("Argument Should be Numeric\n", 2);
			return (0);
		}
		arg++;
	}
	return (1);
}

int	check_args(int number_arg, char **args, char *save)
{
	if (number_arg < 5 || number_arg > 6)
	{
		ft_putstr_fd("Wrong Number of Arguments\n", 2);
		return (0);
	}
	args++;
	while (*args != NULL)
	{
		if (isnum(*args) == 0)
			return (0);
		else if (ft_atoi(*args) == -1)
		{
			ft_putstr_fd("Argument is too Big\n", 2);
			return (0);
		}
		else if (!(**args))
		{
			ft_putstr_fd("Argument Should not be Empty\n", 2);
			return (0);
		}
		args++;
	}
	args = &save;
	return (1);
}

void	add_info(t_info *start_info, char **argv)
{
	int i;

	i = 0;
	argv++;
	while (*argv && argv)
	{
		if (i == 0)
			start_info->number_of_phil = ft_atoi(*argv);
		else if (i == 1)
			start_info->time_to_die = ft_atoi(*argv);
		else if (i == 2)
			start_info->time_to_eat = ft_atoi(*argv);
		else if (i == 3)
			start_info->time_to_sleep = ft_atoi(*argv);
		else if (i == 4)
			start_info->num_to_eat = ft_atoi(*argv);
		argv++;
		i++;
	}
	if (i == 4)
		start_info->num_to_eat = -1;

	printf("[%d]\n", start_info->number_of_phil);
	printf("[%d]\n", start_info->time_to_die);
	printf("[%d]\n", start_info->time_to_eat);
	printf("[%d]\n", start_info->time_to_sleep);
	printf("[%d]\n", start_info->num_to_eat);
}

int	main(int argc, char **argv)
{
	t_info	*start_info;

	if (check_args(argc, argv, *argv) == 0)
		return (1);
	start_info = (t_info *)malloc(sizeof(t_info));
	add_info(start_info, argv);
	return (0);
}

