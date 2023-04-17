/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:40:28 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/17 16:25:33 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*monitor_well_fed(void *p)
{
	int		i;
	t_data	*data;

	data = (t_data *)p;
	i = -1;
	while (++i < data->philo_count && data->keep_eating == true)
	{
		usleep(1000);
		if (well_fed(data, data->philosophers) == false)
			i = -1;
		else
			data->full++;
		if (data->full == data->philo_count)
			break ;
		
		// if (well_fed(data, data->philosophers) == true)
		// {
		// 	pthread_mutex_lock(&data->full_mutex);
		// 	data->full++;
		// 	pthread_mutex_unlock(&data->full_mutex);
		// }
	}
	if (data->keep_eating == true)
	{
			// printf("%d\n", data->full);
		pthread_mutex_lock(&data->keep_eating_mutex);
		data->keep_eating = false;
		pthread_mutex_unlock(&data->keep_eating_mutex);
	}
}

bool	well_fed(t_data *data, t_philo *philosopher)
{
	if (philosopher->meals_eaten >= data->meal_count)
	{
		make_(philosopher, FULL);
		return (true);
	}
	return (false);
}
