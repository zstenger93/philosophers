#include "../../includes/philosophers.h"

void	*monitor_death(void *p)
{
	int		i;
	int		k;
	t_data  *data;

	i = -1;
	k = -1;
	data = (t_data *)p;
	while (++i < data->philo_count && data->keep_eating == true)
	{
		if (is_philo_dead(&data->philosophers[i]) == true)
		{
			while (++k < data->philo_count)
				make_(&data->philosophers[k], DEAD);
			break ;
		}
		if (i == data->philo_count - 1)
			i = -1;
		usleep(1000);
	}
}

bool	is_philo_dead(t_philo *philosopher)
{
	uint64_t	start;
	uint64_t	lst_t_eaten;

	pthread_mutex_lock(&philosopher->last_time_eaten_mutex);
	lst_t_eaten = philosopher->last_time_eaten;
	pthread_mutex_unlock(&philosopher->last_time_eaten_mutex);
	start = current_time();
	if (start - lst_t_eaten > philosopher->data->death_time
		&& (philosopher->data->death_time
		< (philosopher->data->eat_time + philosopher->data->sleep_time)))
	{
		philosopher->data->keep_eating = false;
		print_death(lst_t_eaten, philosopher->index, DIED, philosopher->data);
		make_(philosopher, DEAD);
		return (true);
	}
	return (false);
}

void	print_death(uint64_t time, int index, char *state, t_data *data)
{
	uint64_t	start;
	uint64_t	time2;
	uint64_t	diff;

	start = start_time(data);
	time2 = current_time() - start;
	diff = time2 + (data->death_time - time2) + 2;
	pthread_mutex_lock(&data->print_mutex);
	printf("\033[1;37m%lu \033[1;31m%d\033[0;39m %s\n", diff, index, state);
	pthread_mutex_unlock(&data->print_mutex);
}

void	*monitor_well_fed(void *p)
{
	int		i;
	t_data	*data;

	data = (t_data *)p;
	i = -1;
	while (++i < data->philo_count && data->keep_eating == true)
	{
		usleep(1000);
		if (well_fed(data, data->philosophers) == false)
			i = -1;
		// if (well_fed(data, data->philosophers) == true)
		// {
		// 	if (data->full == data->philo_count)
		// 		break ;
		// 	pthread_mutex_lock(&data->full_mutex);
		// 	data->full++;
		// 	pthread_mutex_unlock(&data->full_mutex);
		// }
	}
	if (data->keep_eating == true)
	{
			// printf("%d\n", data->full);
		pthread_mutex_lock(&data->keep_eating_mutex);
		data->keep_eating = false;
		pthread_mutex_unlock(&data->keep_eating_mutex);
	}
}

bool	well_fed(t_data *data, t_philo *philosopher)
{
	if (philosopher->meals_eaten >= data->meal_count)
	{
		make_(philosopher, FULL);
		return (true);
	}
	return (false);
}
