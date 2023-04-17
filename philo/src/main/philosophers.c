/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:38 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/17 11:21:40 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_dining_table(&data, argc, argv) == false)
		return (1);
	if (threads(&data) == false)
		return (1);
	free_all(&data);
	return (0);
}