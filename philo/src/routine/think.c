#include "../../includes/philosophers.h"

int think(t_philo *philosopher)
{
	if (state_of(philosopher) == DEAD)
		return (false);
	make_(philosopher, THINK);
	print_state(philosopher->data, philosopher->index, THINKIN);
	return (true);
}