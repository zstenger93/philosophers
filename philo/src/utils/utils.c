#include "../../includes/philosophers.h"

int	ft_atoi(const char *str)
{
	int	z;
	int	res;
	int	sign;

	z = 0;
	res = 0;
	sign = 1;
	while (str[z] == ' ' || str[z] == '\f' || str[z] == '\n' || str[z] == '\r'
		|| str[z] == '\t' || str[z] == '\v')
			z++;
	if (str[z] == '-')
	{
		sign *= (-1);
		z++;
	}
	else if (str[z] == '+')
		z++;
	while (str[z] >= '0' && str[z] <= '9')
	{
		res = res * 10 + str[z] - '0';
		z++;
	}
	return (res * sign);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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
