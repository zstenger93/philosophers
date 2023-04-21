/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:46 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/21 11:03:41 by zstenger         ###   ########.fr       */
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

# define EATIN "\033[1;34mis eating\033[0;39m"
# define SLEEPIN "\033[1;32mis sleeping\033[0;39m"
# define THINKIN "\033[1;36mis thinking\033[0;39m"
# define DIED "\033[1;31mdied\033[0;39m"
# define FORK "\033[1;37mhas taken a fork\033[0;39m"

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
	pthread_mutex_t	*forks;
	u_int64_t		eat_time;
	pthread_t		*p_threads;
	u_int64_t		start_time;
	u_int64_t		sleep_time;
	u_int64_t		death_time;
	pthread_mutex_t	full_mutex;
	pthread_t		full_count;
	int				meal_count;
	pthread_t		alive_count;
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
void		print_usage(void);
void		usage(int argc, char **argv);
void		input_check(int argc, char **argv);

// INITIALIZE
void		init_forks(t_data *data);
bool		phillocate(t_data *data);
void		init_philosophers(t_data *data);
bool		init_data(t_data *data, int argc, char **argv);
bool		init_dining_table(t_data *data, int argc, char **argv);

// THREADS
int			threads(t_data *data);
int			join_threads(t_data *data);
int			create_threads(t_data *data);

// ROUTINE
void		*routine(void *p);
	// EAT
void		*monitor_death(void *p);
int			eat(t_philo *philosopher);
void		*monitor_well_fed(void *p);
void		init_death_sentence(t_data *data);
void		meal_counter(t_philo *philosopher);
bool		is_philo_dead(t_philo *philosopher);
bool		well_fed(t_data *data, t_philo *philosopher);
void		print_death(uint64_t time, int index, char *state, t_data *data);
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
t_state		state_of(t_philo *philosopher);
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