/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:40:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/23 07:50:46 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	threads(t_data *data)
{
	create_threads(data);
	join_threads(data);
}

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
	ret = pthread_create(&data->alive_count, NULL,
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

void	join_threads(t_data *data)
{
	int	i;
	int	ret;

	i = -1;
	ret = pthread_join(data->alive_count, NULL);
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
