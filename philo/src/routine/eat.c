#include "../../includes/philosophers.h"


int eat(t_philo *philosopher)
{
	u_int64_t	start;
	uint64_t	time;

	if (grab_forks(philosopher) != 0)
		return (false);
	make_(philosopher, EAT);
	print_state(philosopher->data, philosopher->index, EATIN);
	last_time_eaten(philosopher);
	start = current_time();
	time = eat_time(philosopher->data);
	while (current_time() - start < time)
		usleep(500);
	meal_counter(philosopher);
	drop_forks(philosopher);
	return (true);  
}

void    meal_counter(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->meals_eaten_mutex);
	philosopher->meals_eaten++;
	if (philosopher->meals_eaten == philosopher->data->meal_count)
		philosopher->full = true;
	pthread_mutex_unlock(&philosopher->meals_eaten_mutex);
}

void	last_time_eaten(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->last_time_eaten_mutex);
	philosopher->last_time_eaten = current_time();
	pthread_mutex_unlock(&philosopher->last_time_eaten_mutex);
}

uint64_t	eat_time(t_data *data)
{
	uint64_t	eat_time;
	pthread_mutex_lock(&data->eat_time_mutex);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->eat_time_mutex);
	return (eat_time);
}
