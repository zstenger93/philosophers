#include "../../includes/philosophers.h"

t_state	state_of(t_philo *philosopher)
{
	t_state	state;

	pthread_mutex_lock(&philosopher->state_mutex);
	state = philosopher->state;
	pthread_mutex_unlock(&philosopher->state_mutex);
	return (state);
}

uint64_t    start_time(t_data *data)
{
	uint64_t    time;

	pthread_mutex_lock(&data->start_time_mutex);
	time = data->start_time;
	pthread_mutex_unlock(&data->start_time_mutex);
	return (time);
}

u_int64_t	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}