/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:18:06 by ralves-e          #+#    #+#             */
/*   Updated: 2024/09/21 12:18:19 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **args, void (*del)(void *))
{
	int	i;

	i = 0;
	while (args[i])
	{
		del(args[i]);
		i++;
	}
	del(args);
}
