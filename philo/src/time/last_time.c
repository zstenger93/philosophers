/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:38:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/17 11:38:50 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

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
