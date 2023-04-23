/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:38:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/23 13:46:14 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	last_time_eaten(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->last_time_eaten_mutex);
	philosopher->last_time_eaten = current_time();
	pthread_mutex_unlock(&philosopher->last_time_eaten_mutex);
}
