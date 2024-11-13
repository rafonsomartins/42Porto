/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 23:34:07 by ralves-e          #+#    #+#             */
/*   Updated: 2024/04/13 23:42:51 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len_s;

	len_s = ft_strlen(s);
	res = malloc(sizeof(char) * (len_s + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, s, len_s + 1);
	return (res);
}
