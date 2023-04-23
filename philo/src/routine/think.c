/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:31:55 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/23 13:26:31 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	think(t_philo *philosopher)
{
	make_(philosopher, THINK);
	print_state(philosopher->data, philosopher->index, THINKIN);
}
