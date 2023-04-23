/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:32:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/23 13:48:05 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	take_a_nap(t_philo *philosopher)
{
	uint64_t	start;
	uint64_t	nap_time;

	make_(philosopher, SLEEP);
	print_state(philosopher->data, philosopher->index, SLEEPIN);
	pthread_mutex_lock(&philosopher->data->start_time_mutex);
	start = current_time();
	nap_time = philosopher->data->sleep_time;
	pthread_mutex_unlock(&philosopher->data->start_time_mutex);
	while (current_time() - start < nap_time)
		usleep(500);
}
