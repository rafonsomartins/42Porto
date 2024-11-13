/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:40:20 by ralves-e          #+#    #+#             */
/*   Updated: 2024/10/16 19:40:29 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(const char *string, char s)
{
	int		i;
	char	*res;

	i = 0;
	while (string[i] != s && string[i] != '\0')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, string, i + 1);
	res[i] = '\0';
	return (res);
}
