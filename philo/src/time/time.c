/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:42:19 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/24 13:38:27 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
	get the current time and return it in milliseconds
*/
u_int64_t	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}

uint64_t	start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->start_time_mutex);
	time = data->start_time;
	pthread_mutex_unlock(&data->start_time_mutex);
	return (time);
}

uint64_t	eat_time(t_data *data)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&data->eat_time_mutex);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->eat_time_mutex);
	return (eat_time);
}
