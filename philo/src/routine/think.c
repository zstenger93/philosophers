/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:31:55 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/21 10:27:11 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	think(t_philo *philosopher)
{
	if (philosopher->data->philo_count > 1)
	{
		make_(philosopher, THINK);
		print_state(philosopher->data, philosopher->index, THINKIN);
	}
}
