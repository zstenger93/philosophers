/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:40:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/24 11:37:58 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	threads(t_data *data)
{
	create_threads(data);
	join_threads(data);
}

// one thread for each philo and 1-1 for full and death
void	create_threads(t_data *data)
{
	int	i;
	int	ret;

	i = -1;
	data->start_time = current_time();
	while (++i < data->philo_count)
	{
		ret = pthread_create(&data->p_threads[i], NULL,
				&routine, &data->philosophers[i]);
		if (print_pthread_create_failed(data, ret) == true)
			return ;
	}
	ret = pthread_create(&data->alive, NULL,
			&monitor_death, data);
	if (print_pthread_create_failed(data, ret) == true)
		return ;
	if (data->meal_count > 0)
	{
		ret = pthread_create(&data->full_count, NULL,
				&monitor_well_fed, data);
		if (print_pthread_create_failed(data, ret) == true)
			return ;
	}
}

// waiting for all the threads to finish
void	join_threads(t_data *data)
{
	int	i;
	int	ret;

	i = -1;
	ret = pthread_join(data->alive, NULL);
	if (print_pthread_join_failed(data, ret) == true)
		return ;
	if (data->meal_count > 0)
	{
		ret = pthread_join(data->full_count, NULL);
		if (print_pthread_join_failed(data, ret) == true)
			return ;
	}
	while (++i < data->philo_count)
	{
		ret = pthread_join(data->p_threads[i], NULL);
		if (print_pthread_join_failed(data, ret) == true)
			return ;
	}
}

int	print_pthread_create_failed(t_data *data, int ret)
{
	if (ret != 0)
	{
		printf("pthread_create() failed\n");
		data->exit_code = 1;
		return (true);
	}
	return (false);
}

int	print_pthread_join_failed(t_data *data, int ret)
{
	if (ret != 0)
	{
		printf("pthread_join() failed\n");
		data->exit_code = 1;
		return (true);
	}
	return (false);
}
