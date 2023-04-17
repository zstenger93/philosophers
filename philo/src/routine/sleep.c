/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:32:22 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/17 15:38:56 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	take_a_nap(t_philo *philosopher)
{
	uint64_t    start;
	uint64_t	time;

	make_(philosopher, SLEEP);
	print_state(philosopher->data, philosopher->index, SLEEPIN);
	start = current_time();
	time = eat_time(philosopher->data);
	while (current_time() - start < time)
		usleep(500);
}
