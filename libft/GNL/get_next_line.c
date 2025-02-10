/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:44:33 by ralves-e          #+#    #+#             */
/*   Updated: 2024/05/18 15:11:50 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return(char **buf, char **rest, char **final)
{
	if (*buf)
	{
		free(*buf);
		*buf = 0;
	}
	if (*rest)
	{
		free(*rest);
		*rest = 0;
	}
	if (*final)
	{
		free(*final);
		*final = 0;
	}
	return (0);
}

char	*last_line(char **final, char ***rest, char ***buf)
{
	if (*final)
		free(*final);
	if (!(*rest))
		return (**buf);
	free(**rest);
	**rest = 0;
	if (**buf && !(***buf))
	{
		free(**buf);
		**buf = 0;
	}
	return (**buf);
}

char	*inside_the_while(char **rest, char **buf, char **final)
{
	char	*foo;

	foo = (char *)malloc(sizeof(char)
			* (*final - *buf + ft_strlen(*rest) + 2));
	if (!foo)
		return (0);
	ft_strlcpy(foo, *rest, ft_strlen(*rest) + 1);
	ft_strlcpy(foo + ft_strlen(*rest), *buf, *final - *buf + 2);
	if (*rest)
		free(*rest);
	*rest = (char *)malloc(sizeof(char)
			* (ft_strlen(*buf) - (*final - *buf) + 1));
	if (!rest)
		ft_return(rest, buf, final);
	ft_strlcpy(*rest, (*final + 1), (ft_strlen(*buf) - (*final - *buf)));
	free(*buf);
	return (foo);
}

char	*ft_get_at_work(int s, char **rest, char **buf, int fd)
{
	char	*final;
	char	*empty_str;

	final = 0;
	empty_str = 0;
	if (!rest)
		rest = &empty_str;
	while (s > 0)
	{
		final = ft_strchr(*buf, '\n');
		if (final)
			return (inside_the_while(rest, buf, &final));
		final = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!final)
			return (ft_return(&final, rest, buf));
		s = read(fd, final, BUFFER_SIZE);
		final[s] = '\0';
		if (!s)
			return (last_line(&final, &rest, &buf));
		if (s < 0)
			return (ft_return(&final, buf, rest));
		*buf = ft_realloc(*buf, final);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buf;
	int				s;
	static char		*rest = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (rest)
	{
		buf = rest;
		rest = 0;
		return (ft_get_at_work(BUFFER_SIZE, &rest, &buf, fd));
	}
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	s = read(fd, buf, BUFFER_SIZE);
	if (s <= 0)
		return (ft_return(&rest, &buf, &buf));
	buf[s] = '\0';
	return (ft_get_at_work(s, &rest, &buf, fd));
}
