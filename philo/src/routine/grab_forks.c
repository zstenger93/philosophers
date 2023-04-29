/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:36:16 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/29 09:01:09 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
	no need for checks on taking the forks, because it only goes thru the
	function if it can take both forks. Else it's trying to grab them until
	they are available or they died because the time runs out.
*/
void	grab_forks(t_philo *philosopher)
{
	if (philosopher->index % 2 == 0)
	{
		grab_right_fork(philosopher);
		grab_left_fork(philosopher);
	}
	else
	{
		grab_left_fork(philosopher);
		grab_right_fork(philosopher);
	}
}

void	grab_right_fork(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	print_state(philosopher->data, philosopher->index, FORK);
}

void	grab_left_fork(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	print_state(philosopher->data, philosopher->index, FORK);
}
