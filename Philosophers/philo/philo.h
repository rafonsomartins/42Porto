/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:19:29 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/08 14:44:11 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <ctype.h>

typedef struct s_args
{
	pthread_mutex_t	**mutex;
	pthread_mutex_t	stdout_mutex;
	pthread_mutex_t	someone_dead_mutex;
	pthread_mutex_t	init_time_mutex;
	unsigned long	init_time;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_to_die;
	int				someone_dead;
	int				num_philo;
	int				nbr_to_eat;
}	t_args;

typedef struct s_philo
{
	t_args			*args;
	pthread_t		philo;
	pthread_mutex_t	last_eat_mutex;
	pthread_mutex_t	nbr_eaten_mutex;
	unsigned long	last_eat;
	int				forks[2];
	int				philo_id;
	int				nbr_eaten;
	int				is_dead;
}	t_philo;

//sources
int				check_str(char **argv);
void			init_var(t_args *args, t_philo **philos);
int				parser(t_args *args, int argc, char **argv);
void			run_sim(t_args *args, t_philo *philos);
void			check_philos(t_args *args, t_philo *philos);
int				free_stuff(t_args *args, t_philo **philos, int one_philo);
// philos
void			*routine(void *args);
void			init_var_philo(t_philo *philo);
//  actions
void			*philo_eat(t_philo *philo);
void			*philo_sleep(t_philo *philo);
void			*philo_think(t_philo *philo);

//utils
void			ft_sleep(unsigned int milliseconds);
unsigned long	ft_actual_time(void);
void			exit_function(t_args *args, t_philo **philos);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);

#endif