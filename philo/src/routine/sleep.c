#include "../../includes/philosophers.h"

//sleep
int take_a_nap(t_philo *philosopher)
{
	uint64_t    start;
	uint64_t	time;

	make_(philosopher, SLEEP);
	if (state_of(philosopher) == DEAD)
		return (false);
	print_state(philosopher->data, philosopher->index, SLEEPIN);
	start = current_time();
	time = eat_time(philosopher->data);
	while (current_time() - start < time)
		usleep(500);
	return (true);
}
