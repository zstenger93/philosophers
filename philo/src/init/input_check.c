/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:24:55 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/21 14:02:31 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/philosophers.h"

void	input_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		usage();
	if (is_all_digit(argc, argv, 0, -1) == false)
		usage();
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		usage();
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		usage();
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
		usage();
}

bool	is_all_digit(int argc, char **argv, int i, int j)
{
	while (++i < argc)
	{
		j = 0;
		while (argv[i][++j] != '\0')
		{
			if (argv[i][j] < '0' || '9' < argv[i][j])
				return (false);
		}
	}
	return (true);
}

void	usage(void)
{
	print_usage();
	exit(0);
}

void	print_usage(void)
{
	printf(TAKES);
	printf(ONLYNUM);
	printf(FOUR_ARG);
	printf(FIVE_ARG);
	printf(SIXTY);
	printf(PHILO);
	printf(PHILO_NUM1);
	printf(PHILO_NUM2);
	printf(PHILO_DIE);
	printf(PHILO_EAT);
	printf(COLOR_LAST);
	printf(PHILO_SLEEP);
	printf(OPTIONAL);
	printf(OPTIONAL_END);
	printf("\n");
}
