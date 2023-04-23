/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:40:32 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/23 15:05:01 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

//if there is 1-2 ms diff between DT and ET+ST don't sleep or it's random death
void	*monitor_death(void *p)
{
	int		i;
	int		k;
	t_data	*data;
	int		philos;

	i = -1;
	k = -1;
	data = (t_data *)p;
	philos = data->philo_count;
	while (++i < philos && keep_eating(data) == true)
	{
		if (is_philo_dead(&data->philosophers[i]) == true)
		{
			while (++k < philos)
				make_(&data->philosophers[k], DEAD);
			break ;
		}
		if (i == philos - 1)
			i = -1;
		if (((data->eat_time + data->sleep_time) - 1 != data->death_time)
			&& ((data->eat_time + data->sleep_time) - 2 != data->death_time))
			usleep(1000);
	}
	return (NULL);
}

bool	is_philo_dead(t_philo *philo)
{
	uint64_t	time;
	uint64_t	lst_t_eaten;
	u_int64_t	death_time;

	pthread_mutex_lock(&philo->last_time_eaten_mutex);
	lst_t_eaten = philo->last_time_eaten;
	time = current_time();
	death_time = philo->data->death_time;
	pthread_mutex_unlock(&philo->last_time_eaten_mutex);
	if (((lst_t_eaten > death_time) && (time - lst_t_eaten > death_time))
		|| (time - lst_t_eaten > death_time && (death_time
				< (philo->data->eat_time + philo->data->sleep_time))))
	{
		pthread_mutex_lock(&philo->data->keep_eating_mutex);
		philo->data->keep_eating = false;
		pthread_mutex_unlock(&philo->data->keep_eating_mutex);
		print_death(philo->index, DIED, philo->data);
		make_(philo, DEAD);
		return (true);
	}
	return (false);
}

void	print_death(int index, char *state, t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->print_mutex);
	time = current_time() - start_time(data);
	printf("\033[1;37m%llu \033[1;31m%d\033[0;39m %s\n", time, index, state);
	pthread_mutex_unlock(&data->print_mutex);
}

int	keep_eating(t_data *data)
{
	int	keep_eating;

	pthread_mutex_lock(&data->keep_eating_mutex);
	keep_eating = data->keep_eating;
	pthread_mutex_unlock(&data->keep_eating_mutex);
	return (keep_eating);
}
