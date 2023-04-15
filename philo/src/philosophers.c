
#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	usage(argc, argv);
	// printf("here\n");
	input_check(argc, argv);
	if (!init_dining_table(&data, argc, argv))
		return (1);
	if (threads(&data) == false)
		return (1);
	free_all(&data);
	return (0);
}
