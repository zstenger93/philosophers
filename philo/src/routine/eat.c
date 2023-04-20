/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:37:40 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/20 14:38:48 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	eat(t_philo *philosopher)
{
	u_int64_t	start;
	uint64_t	time;

	grab_forks(philosopher);
	last_time_eaten(philosopher);
	make_(philosopher, EAT);
	print_state(philosopher->data, philosopher->index, EATIN);
	start = current_time();
	time = eat_time(philosopher->data);
	while (current_time() - start < time)
		usleep(500);
	meal_counter(philosopher);
	drop_forks(philosopher);
	return (true);
}

void	meal_counter(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->meals_eaten_mutex);
	philosopher->meals_eaten++;
	if (philosopher->meals_eaten == philosopher->data->meal_count)
		philosopher->full = true;
	pthread_mutex_unlock(&philosopher->meals_eaten_mutex);
}
