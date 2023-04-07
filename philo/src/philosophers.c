
#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	usage(argc);
	if (philosophers(argc, argv) != 0)
		return (1);
	return (0);
}

int	philosophers(int argc, char **argv)
{
	t_data	data;

	if (!init_dining_table(&data, argc, argv))
		return (1);
	init_philosophers(&data);
	init_forks(&data);
	threads(&data);
	free_data(&data);
}

int	init_dining_table(t_data *data, int argc, char **argv)
{
	data->keep_eating = true;
	data->philo_count = atoi(argv[1]);
}

void	usage(int argc)
{
	if (argc != 5 || argc != 6)
		print_usage();
	return ;
}
