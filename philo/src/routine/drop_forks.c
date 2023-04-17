/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:36:11 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/17 12:11:39 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	drop_right_fork(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->right_fork);
}

void	drop_left_fork(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->left_fork);
}

void	drop_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}
