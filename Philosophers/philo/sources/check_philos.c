/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:02:43 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/08 14:44:05 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_deaths(t_args *args, t_philo *philos, int *getout, int i)
{
	long long	timestamp;

	pthread_mutex_lock(&(philos[i].last_eat_mutex));
	if (!philos[i].last_eat)
		philos[i].last_eat = args->init_time;
	if ((ft_actual_time() - philos[i].last_eat) >= args->time_to_die)
	{
		pthread_mutex_lock(&(args->stdout_mutex));
		pthread_mutex_lock(&(args->someone_dead_mutex));
		args->someone_dead = 1;
		pthread_mutex_unlock(&(args->someone_dead_mutex));
		timestamp = ft_actual_time() - args->init_time;
		printf("%lld %d died\n", timestamp, philos[i].philo_id);
		pthread_mutex_unlock(&(args->stdout_mutex));
		*getout = 2;
		pthread_mutex_unlock(&(philos[i].last_eat_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philos[i].last_eat_mutex));
	return (0);
}

int	get_getout(t_args *args, t_philo *philos)
{
	int	getout;
	int	i;

	i = args->num_philo;
	getout = 1;
	while (i-- > 0)
	{
		pthread_mutex_lock(&(philos[i].nbr_eaten_mutex));
		if (args->nbr_to_eat == -1 || philos[i].nbr_eaten < args->nbr_to_eat)
			getout = 0;
		pthread_mutex_unlock(&(philos[i].nbr_eaten_mutex));
		if (check_deaths(args, philos, &getout, i))
			break ;
	}
	return (getout);
}

void	check_philos(t_args *args, t_philo *philos)
{
	int			getout;

	getout = 0;
	while (!getout)
		getout = get_getout(args, philos);
	if (getout == 1)
	{
		pthread_mutex_lock(&(args->someone_dead_mutex));
		args->someone_dead = 505;
		pthread_mutex_unlock(&(args->someone_dead_mutex));
	}
}
