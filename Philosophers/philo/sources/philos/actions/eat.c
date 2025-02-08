/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:39:09 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/08 14:44:26 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../philo.h"

int	take1stfork(t_philo *philo, long long *timestamp)
{
	pthread_mutex_lock(philo->args->mutex[philo->forks[0] - 1]);
	pthread_mutex_lock(&(philo->args->stdout_mutex));
	pthread_mutex_lock(&(philo->args->someone_dead_mutex));
	pthread_mutex_lock(&(philo->args->init_time_mutex));
	*timestamp = ft_actual_time() - philo->args->init_time;
	if (philo->args->someone_dead == 0)
		printf("%lld %d has taken a fork\n", *timestamp, philo->philo_id);
	else
	{
		pthread_mutex_unlock(&(philo->args->init_time_mutex));
		pthread_mutex_unlock(&(philo->args->stdout_mutex));
		pthread_mutex_unlock(&(philo->args->someone_dead_mutex));
		pthread_mutex_unlock(philo->args->mutex[philo->forks[0] - 1]);
		return (1);
	}
	pthread_mutex_unlock(&(philo->args->init_time_mutex));
	pthread_mutex_unlock(&(philo->args->someone_dead_mutex));
	pthread_mutex_unlock(&(philo->args->stdout_mutex));
	return (0);
}

void	unlock(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->last_eat_mutex));
	pthread_mutex_unlock(&(philo->args->stdout_mutex));
	pthread_mutex_unlock(&(philo->args->someone_dead_mutex));
	pthread_mutex_unlock(&(philo->args->init_time_mutex));
	pthread_mutex_unlock(philo->args->mutex[philo->forks[0] - 1]);
	pthread_mutex_unlock(philo->args->mutex[philo->forks[1] - 1]);
}

void	start_eating(t_philo *philo, long long *timestamp)
{
	pthread_mutex_lock(&(philo->nbr_eaten_mutex));
	philo->nbr_eaten++;
	pthread_mutex_unlock(&(philo->nbr_eaten_mutex));
	printf("%lld %d is eating\n", *timestamp, philo->philo_id);
	return ;
}

int	take2ndfork(t_philo *philo, long long *timestamp)
{
	pthread_mutex_lock(philo->args->mutex[philo->forks[1] - 1]);
	pthread_mutex_lock(&(philo->last_eat_mutex));
	pthread_mutex_lock(&(philo->args->stdout_mutex));
	pthread_mutex_lock(&(philo->args->someone_dead_mutex));
	pthread_mutex_lock(&(philo->args->init_time_mutex));
	*timestamp = ft_actual_time() - philo->args->init_time;
	philo->last_eat = ft_actual_time();
	if (philo->args->someone_dead == 0)
		start_eating(philo, timestamp);
	else
	{
		unlock(philo);
		return (1);
	}
	pthread_mutex_unlock(&(philo->last_eat_mutex));
	pthread_mutex_unlock(&(philo->args->stdout_mutex));
	pthread_mutex_unlock(&(philo->args->init_time_mutex));
	pthread_mutex_unlock(&(philo->args->someone_dead_mutex));
	ft_sleep(philo->args->time_to_eat);
	pthread_mutex_unlock(philo->args->mutex[philo->forks[0] - 1]);
	pthread_mutex_unlock(philo->args->mutex[philo->forks[1] - 1]);
	return (0);
}

void	*philo_eat(t_philo *philo)
{
	long long	timestamp;

	if (take1stfork(philo, &timestamp))
		return (0);
	if (take2ndfork(philo, &timestamp))
		return (0);
	return (philo_sleep(philo));
}
