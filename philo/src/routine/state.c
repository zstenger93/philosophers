/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:43:18 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/23 10:08:03 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

t_state	state_of_(t_philo *philosopher)
{
	t_state	state;

	pthread_mutex_lock(&philosopher->state_mutex);
	state = philosopher->state;
	pthread_mutex_unlock(&philosopher->state_mutex);
	return (state);
}
