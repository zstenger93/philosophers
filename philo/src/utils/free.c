/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:29:28 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/22 15:19:20 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->eat_time_mutex);
	pthread_mutex_destroy(&data->death_time_mutex);
	pthread_mutex_destroy(&data->sleep_time_mutex);
	pthread_mutex_destroy(&data->start_time_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->philo_count_mutex);
	pthread_mutex_destroy(&data->keep_eating_mutex);
	pthread_mutex_destroy(&data->full_mutex);
	while (++i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philosophers[i].state_mutex);
		pthread_mutex_destroy(&data->philosophers[i].meals_eaten_mutex);
		pthread_mutex_destroy(&data->philosophers[i].last_time_eaten_mutex);
	}
	free(data->philosophers);
	free(data->p_threads);
	free(data->forks);
}
