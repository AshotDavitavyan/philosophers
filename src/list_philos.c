#include "../includes/philo.h"

t_philo	*add_philo(int index, t_info *info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->index = index;
	philo->last_time_ate = 0;
	philo->info = info;
	philo->next = NULL;
	philo->prev = NULL;
	pthread_mutex_init(&philo->fork, 0);
	return (philo);
}

t_philo	*philoadd_back(t_philo *to_add, t_philo *philo)
{
	t_philo	*head;

	head = philo;
	while (philo->next != NULL)
		philo = philo->next;
	philo->next = to_add;
	to_add->prev = philo;
	return (head);
}

void	circle_list(t_philo *head)
{
	t_philo	*tail;

	tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	head->prev = tail;
	tail->next = head;
}

t_philo	*create_philos(t_info *start_info)
{
	t_philo	*to_return;
	int		i;

	i = 0;
	while (start_info->number_of_phil > i)
	{
		if (i == 0)
			to_return = add_philo(i + 1, start_info);
		else
			to_return = philoadd_back(add_philo(i + 1, start_info), to_return);
		i++;
	}
	if (i > 0)
		circle_list(to_return);
	return (to_return);
}