/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:35:26 by ralves-e          #+#    #+#             */
/*   Updated: 2025/02/08 14:40:02 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	free_stuff(t_args *args, t_philo **philos, int one_philo)
{
	int	i;

	i = args->num_philo;
	while (--i >= 0)
	{
		if (args->mutex[i])
			pthread_mutex_destroy(args->mutex[i]);
		if (!one_philo)
			pthread_mutex_destroy(&((*philos)[i].last_eat_mutex));
	}
	i = args->num_philo;
	while (--i >= 0)
	{
		if (args->mutex[i])
			free(args->mutex[i]);
	}
	pthread_mutex_destroy(&(args->someone_dead_mutex));
	pthread_mutex_destroy(&(args->stdout_mutex));
	pthread_mutex_destroy(&(args->init_time_mutex));
	if (args->mutex)
		free(args->mutex);
	if (*philos)
		free(*philos);
	return (0);
}
