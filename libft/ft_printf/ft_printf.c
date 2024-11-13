/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:23:09 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/11 18:39:15 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_conversion_hex(char c, va_list ap)
{
	char	*str;
	int		res;

	res = 0;
	if (c == 'p')
	{
		str = va_arg(ap, void *);
		if (!str)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		res = 2;
		ft_putstr_fd("0x", 1);
	}
	str = ft_itoa_hexa((unsigned long long)va_arg(ap, unsigned int));
	if (c == 'X')
		str = ft_toupper_str(str);
	ft_putstr_fd(str, 1);
	res += ft_strlen(str);
	free(str);
	return (res);
}

int	ft_put_conversion_2(char c, va_list ap)
{
	char	*str;
	int		res;

	res = 0;
	if (c == 'd' || c == 'i')
	{
		str = ft_itoa(va_arg(ap, int));
		ft_putstr_fd(str, 1);
		res = ft_strlen(str);
		free(str);
		return (res);
	}
	if (c == 'u')
	{
		str = ft_utoa(va_arg(ap, unsigned int));
		ft_putstr_fd(str, 1);
		res = ft_strlen(str);
		free(str);
		return (res);
	}
	return (ft_put_conversion_hex(c, ap));
}

int	ft_put_conversion_1(char c, va_list ap)
{
	char	*str;

	if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(ap, int), 1);
		return (1);
	}
	if (c == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (ft_put_conversion_2(c, ap));
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			res++;
		}
		else
		{
			str++;
			res += ft_put_conversion_1(*str, ap);
		}
		str++;
	}
	va_end(ap);
	return (res);
}
