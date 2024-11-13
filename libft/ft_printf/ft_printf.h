/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:03:44 by ralves-e          #+#    #+#             */
/*   Updated: 2024/07/10 19:03:30 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_toupper_str(char *str);
char	*ft_itoa_hexa(unsigned long long n);

#endif
