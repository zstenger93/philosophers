#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "dead"
# define PICK_FORK "has taken a fork"



typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	t_state			state;
	struct s_data	*data;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	m_state;
}	t_philo;

typedef enum e_state
{
    IDLE,
    EAT,
    SLEEP,
    THINK,
    DEAD,
    FULL
}   t_state;

typedef struct s_data
{
	int				philo_count;
	int				meal_count;
	int				full_count;
	int				keep_eating;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
}	t_data;

#endif