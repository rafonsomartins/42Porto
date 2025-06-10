/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:25:22 by ralves-e          #+#    #+#             */
/*   Updated: 2024/09/07 15:28:43 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_var(t_args *args, t_philo **philos)
{
	int	i;

	args->init_time = ft_actual_time();
	i = args->num_philo;
	pthread_mutex_init(&(args->someone_dead_mutex), NULL);
	pthread_mutex_init(&(args->stdout_mutex), NULL);
	pthread_mutex_init(&(args->init_time_mutex), NULL);
	*philos = (t_philo *)malloc((sizeof(t_philo)) * args->num_philo);
	if (!philos)
		exit_function(args, philos);
	args->mutex = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *)
			* args->num_philo);
	if (!args->mutex)
		exit_function(args, philos);
	args->someone_dead = 0;
	while (--i >= 0)
	{
		args->mutex[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!args->mutex[i])
			exit_function(args, philos);
	}
	i = args->num_philo;
	while (--i >= 0)
		pthread_mutex_init(args->mutex[i], NULL);
	return ;
}
