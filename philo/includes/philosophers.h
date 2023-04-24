/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:46 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/24 11:38:04 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// ROUTINE
# define EATIN "\033[1;34mis eating\033[0;39m"
# define SLEEPIN "\033[1;32mis sleeping\033[0;39m"
# define THINKIN "\033[1;36mis thinking\033[0;39m"
# define DIED "\033[1;31mdied\033[0;39m"
# define FORK "\033[1;37mhas taken a fork\033[0;39m"
// ERROR MESSAGE
# define TAKES "\n\033[1;33mThis program takes only 4 or 5 arguments "
# define ONLYNUM "and those can be only numbers.\n\n\033[1;31m"
# define FOUR_ARG "./philo 4 410 200 200\n\033[1;37mor\n\033[1;31m"
# define FIVE_ARG "./philo 4 410 200 200 2\n\033[1;37mand\n\033[1;31m"
# define SIXTY "Die, Eat and Sleep time should be bigger than 60\n\033[0;39m"
# define PHILO "\n\033[1;34m./philo \033[1;37m-> \033[1;33mexecutable\n"
# define PHILO_NUM1 "\033[1;34m    4   \033[1;37"
# define PHILO_NUM2 "m-> \033[1;33mamount of philosophers at the table\n"
# define PHILO_DIE "\033[1;34m   410  \033[1;37m-> \033[1;33mtime to die\n"
# define PHILO_EAT "\033[1;34m   200  \033[1;37m-> \033[1;33mtime to eat\n"
# define COLOR_LAST "\033[1;34m"
# define PHILO_SLEEP "   200  \033[1;37m-> \033[1;33mtime to sleep\n\033[0;34m"
# define OPTIONAL "    2   \033[1;37m-> \033[1;33mnumber of meals"
# define OPTIONAL_END " (optional)\n\033[0;39m"

typedef enum e_state
{
	IDLE,
	EAT,
	SLEEP,
	THINK,
	FULL,
	DEAD
}	t_state;

typedef struct s_philo
{
	int				full;
	int				index;
	t_state			state;
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	pthread_mutex_t	state_mutex;
	u_int64_t		last_time_eaten;
	pthread_mutex_t	meals_eaten_mutex;
	pthread_mutex_t	last_time_eaten_mutex;
}	t_philo;

typedef struct s_data
{
	int				full;
	pthread_t		alive;
	pthread_mutex_t	*forks;
	u_int64_t		eat_time;
	int				exit_code;
	pthread_t		*p_threads;
	u_int64_t		start_time;
	u_int64_t		sleep_time;
	u_int64_t		death_time;
	pthread_mutex_t	full_mutex;
	pthread_t		full_count;
	int				meal_count;
	pthread_mutex_t	print_mutex;
	int				philo_count;
	int				keep_eating;
	t_philo			*philosophers;
	pthread_mutex_t	eat_time_mutex;
	pthread_mutex_t	death_time_mutex;
	pthread_mutex_t	sleep_time_mutex;
	pthread_mutex_t	start_time_mutex;
	pthread_mutex_t	philo_count_mutex;
	pthread_mutex_t	keep_eating_mutex;
}	t_data;

// INPUT CHECK
void		usage(void);
void		print_usage(void);
void		input_check(int argc, char **argv);
bool		is_all_digit(int argc, char **argv, int i, int j);

// INITIALIZE
void		init_forks(t_data *data);
bool		phillocate(t_data *data);
void		init_philosophers(t_data *data);
bool		init_data(t_data *data, int argc, char **argv);
bool		init_dining_table(t_data *data, int argc, char **argv);

// THREADS
void		threads(t_data *data);
void		join_threads(t_data *data);
void		create_threads(t_data *data);
int			print_pthread_join_failed(t_data *data, int ret);
int			print_pthread_create_failed(t_data *data, int ret);

// ROUTINE
void		*routine(void *p);
int			keep_eating(t_data *data);
	// EAT
void		*monitor_death(void *p);
int			full_count(t_data *data);
void		stop_eating(t_data *data);
int			eat(t_philo *philosopher);
void		*monitor_well_fed(void *p);
void		init_death_sentence(t_data *data);
void		meal_counter(t_philo *philosopher);
bool		is_philo_dead(t_philo *philosopher);
bool		well_fed(t_data *data, t_philo *philosopher);
void		print_death(int index, char *state, t_data *data);
	// THINK
void		think(t_philo *philosopher);
	// SLEEP
void		take_a_nap(t_philo *philosopher);
	// GRAB FORKS
void		grab_forks(t_philo *philo);
void		grab_left_fork(t_philo *philo);
void		grab_right_fork(t_philo *philo);
	// DROP FORKS
void		drop_forks(t_philo *philo);
void		drop_left_fork(t_philo *philo);
void		drop_right_fork(t_philo *philo);

// STATE
t_state		state_of_(t_philo *philosopher);
void		make_(t_philo *philosopher, t_state state);
void		print_state(t_data *data, int index, char *state);

// UTILS
void		free_all(t_data *data);
int			ft_atoi(const char *str);

// TIME
u_int64_t	current_time(void);
uint64_t	eat_time(t_data *data);
uint64_t	start_time(t_data *data);
void		last_time_eaten(t_philo *philosopher);

#endif