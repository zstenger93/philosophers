#include "../../includes/philosophers.h"

void	drop_right_fork(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->right_fork);
}

void	drop_left_fork(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->left_fork);
}

void	drop_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

int	grab_right_fork(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	print_state(philosopher->data, philosopher->index, FORK);
}

int	grab_left_fork(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	print_state(philosopher->data, philosopher->index, FORK);
}

int	grab_forks(t_philo *philosopher)
{
	if (philosopher->index % 2 == 0)
	{
		if (grab_right_fork(philosopher) != 0)
			return (1);
		if (grab_left_fork(philosopher) != 0)
		{
			drop_right_fork(philosopher);
			return (1);
		}
	}
	else
	{
		if (grab_left_fork(philosopher) != 0)
			return (1);
		if (grab_right_fork(philosopher) != 0)
		{
			drop_left_fork(philosopher);
			return (1);
		}
	}
	return (0);
}