/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:38 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/24 10:29:46 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		exit_code;

	input_check(argc, argv);
	if (init_dining_table(&data, argc, argv) == false)
		exit(1);
	threads(&data);
	exit_code = data.exit_code;
	free_all(&data);
	exit(exit_code);
}
