/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:32:46 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/24 11:42:10 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*routine(void *p)
{
	int		philos;
	int		meal_count;
	t_philo	*philosopher;

	philosopher = (t_philo *)p;
	philos = philosopher->data->philo_count;
	pthread_mutex_lock(&philosopher->data->full_mutex);
	meal_count = philosopher->data->meal_count;
	pthread_mutex_unlock(&philosopher->data->full_mutex);
	while (state_of_(philosopher) != DEAD)
	{
		if (meal_count > 0)
			if (keep_eating(philosopher->data) == false)
				break ;
		eat(philosopher);
		if (philos > 1)
		{
			take_a_nap(philosopher);
			think(philosopher);
		}
	}
	return (NULL);
}

void	make_(t_philo *philosopher, t_state state)
{
	pthread_mutex_lock(&philosopher->state_mutex);
	if (philosopher->state != DEAD)
		philosopher->state = state;
	pthread_mutex_unlock(&philosopher->state_mutex);
}

void	print_state(t_data *data, int index, char *state)
{
	uint64_t	time;
	uint64_t	start;

	pthread_mutex_lock(&data->print_mutex);
	start = start_time(data);
	time = current_time() - start;
	if (keep_eating(data) == true)
		printf("\033[1;37m%llu \033[1;31m%d\033[0;39m %s\n", time, index, state);
	pthread_mutex_unlock(&data->print_mutex);
}
