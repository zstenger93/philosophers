/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:32:46 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/18 13:31:51 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*routine(void *p)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)p;
	while (state_of(philosopher) != DEAD)
	{
		eat(philosopher);
		take_a_nap(philosopher);
		think(philosopher);
		// if (state_of(philosopher) == FULL)
		// 	break ;
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

	start = start_time(data);
	time = current_time() - start;
	// printf("%lu, %lu\n", start, time);
	pthread_mutex_lock(&data->print_mutex);
	// if (state == EATIN && time > data->death_time)
	// 	return ;
	if (data->keep_eating == true)
		printf("\033[1;37m%llu \033[1;31m%d\033[0;39m %s\n", time, index, state);
	pthread_mutex_unlock(&data->print_mutex);
}
