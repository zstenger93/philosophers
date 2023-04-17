/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:40:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/17 11:40:49 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	threads(t_data *data)
{
	if (create_threads(data) == false)
		return (false);
	if (join_threads(data) == false)
		return (false);
	return (true);
}

int	create_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = current_time();
	while (++i < data->philo_count)
	{
		if (pthread_create(&data->p_threads[i], NULL,
			&routine, &data->philosophers[i]) != 0)
			return (false);
	}
	if (pthread_create(&data->alive_count, NULL,
		&monitor_death, data))
		return (false);
	if (data->meal_count > 0 && pthread_create(&data->full_count, NULL,
		&monitor_well_fed, data))
		return (false);
	return (true);
}

int	join_threads(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_join(data->alive_count, NULL))
		return (1);
	if (data->meal_count && pthread_join(data->full_count, NULL))
	while (++i < data->philo_count)
	{
		if (pthread_join(data->p_threads[i], NULL) != 0)
			return (false);
	}
	return (true);
}
