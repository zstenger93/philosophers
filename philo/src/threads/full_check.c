/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:40:28 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/23 14:38:56 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*monitor_well_fed(void *p)
{
	int		i;
	t_data	*data;
	int		philos;
	int		full;

	i = -1;
	full = 0;
	data = (t_data *)p;
	philos = data->philo_count;
	while (++i < philos && keep_eating(data) == true)
	{
		usleep(1000);
		if (well_fed(data, data->philosophers) == false)
			i = -1;
		else
			full = full_count(data);
		if (full >= philos)
			break ;
	}
	if (keep_eating(data) == true)
		stop_eating(data);
	return (NULL);
}

bool	well_fed(t_data *data, t_philo *philosopher)
{
	int	meals_eaten;
	int	meal_count;

	pthread_mutex_lock(&philosopher->meals_eaten_mutex);
	meal_count = data->meal_count;
	meals_eaten = philosopher->meals_eaten;
	pthread_mutex_unlock(&philosopher->meals_eaten_mutex);
	if (meals_eaten >= meal_count)
	{
		make_(philosopher, FULL);
		return (true);
	}
	return (false);
}

int	full_count(t_data *data)
{
	int	full;

	pthread_mutex_lock(&data->full_mutex);
	data->full++;
	full = data->full;
	pthread_mutex_unlock(&data->full_mutex);
	return (full);
}

void	stop_eating(t_data *data)
{
	pthread_mutex_lock(&data->keep_eating_mutex);
	data->keep_eating = false;
	pthread_mutex_unlock(&data->keep_eating_mutex);
}
