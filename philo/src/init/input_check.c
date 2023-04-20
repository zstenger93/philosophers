/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:24:55 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/20 16:55:10 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/philosophers.h"

void	input_check(int argc, char **argv)
{
	if (argc == 6 && argv[0][0] == '0')
		exit(0);
	if (argv[1][0] == '1')
		init_death_sentence(argv);
}

void	init_death_sentence(char **argv)
{
	printf("\033[1;37m0 \033[1;31m1 \033[1;37m%s\n", FORK);
	usleep(ft_atoi(argv[2]));
	printf("\033[1;37m%d \033[1;31m1 "
		"\033[1;37m%s\n", (ft_atoi(argv[2]) + 1), "\033[1;31mdied\033[0;39");
	exit(0);
}

void	usage(int argc, char **argv)
{
	int	i;

	if (argc < 5 || (argc == 6 && ft_atoi(argv[5]) <= 0) || argc > 6)
	{
		print_usage();
		exit(0);
	}
}

void	print_usage(void)
{
	printf("This program takes only 4 or 5 arguments:\n");
	printf("./philo 5 600 200 200\n");
	printf("or\n");
	printf("./philo 5 600 200 200 2\n");
}
