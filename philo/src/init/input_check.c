#include "../../includes/philosophers.h"

void    input_check(int argc, char **argv)
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
	printf("\033[1;37m%d \033[1;31m1 \033[1;37m%s\n", (ft_atoi(argv[2]) + 1), "\033[1;31mdied\033[0;39");
	exit(0);
}