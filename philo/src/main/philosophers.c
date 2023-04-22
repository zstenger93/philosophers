/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:38 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/22 15:19:42 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/philosophers.h"

//check threads if return needed
int	main(int argc, char **argv)
{
	t_data	data;
	int		exit_code;

	if (init_dining_table(&data, argc, argv) == false)
		return (1);
	threads(&data);
	exit_code = data.exit_code;
	free_all(&data);
	exit(exit_code);
}
