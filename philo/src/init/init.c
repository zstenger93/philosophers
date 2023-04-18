/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:22:20 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/18 13:32:24 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/philosophers.h"

bool	init_dining_table(t_data *data, int argc, char **argv)
{
	usage(argc, argv);
	if (init_data(data, argc, argv) == true)
	{
		init_philosophers(data);
		init_forks(data);
		return (true);
	}
	else
		return (false);
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		data->philosophers[i].index = i + 1;
		data->philosophers[i].state = IDLE;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].data = data;
		data->philosophers[i].full = false;
		pthread_mutex_init(&data->philosophers[i].meals_eaten_mutex, NULL);
		pthread_mutex_init(&data->philosophers[i].last_time_eaten_mutex, NULL);
		pthread_mutex_init(&data->philosophers[i].state_mutex, NULL);
		last_time_eaten(&data->philosophers[i]);
	}
}

bool	init_data(t_data *data, int argc, char **argv)
{
	data->full = 0;
	data->p_threads = NULL;
	data->meal_count = 0;
	data->philo_count = ft_atoi(argv[1]);
	data->keep_eating = true;
	data->full_count = 0;
	if (argc == 6)
		data->meal_count = ft_atoi(argv[5]);
	pthread_mutex_init(&data->eat_time_mutex, NULL);
	pthread_mutex_init(&data->sleep_time_mutex, NULL);
	pthread_mutex_init(&data->death_time_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->philo_count_mutex, NULL);
	pthread_mutex_init(&data->keep_eating_mutex, NULL);
	pthread_mutex_init(&data->start_time_mutex, NULL);
	pthread_mutex_init(&data->full_mutex, NULL);
	data->death_time = (u_int64_t)ft_atoi(argv[2]);
	data->eat_time = (u_int64_t)ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t)ft_atoi(argv[4]);
	return (phillocate(data));
}

void	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philosophers[0].right_fork = &data->forks[data->philo_count - 1];
	data->philosophers[0].left_fork = &data->forks[0];
	while (++i < data->philo_count)
	{
		data->philosophers[i].right_fork = &data->forks[i - 1];
		data->philosophers[i].left_fork = &data->forks[i];
	}
}

bool	phillocate(t_data *data)
{
	data->philosophers = malloc(sizeof(t_philo) * data->philo_count);
	if (data->philosophers == NULL)
		return (false);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (data->forks == NULL)
	{
		free(data->philosophers);
		return (false);
	}
	data->p_threads = malloc(sizeof(pthread_t) * data->philo_count);
	if (data->p_threads == NULL)
	{
		free(data->philosophers);
		free(data->forks);
		return (false);
	}
	return (true);
}
