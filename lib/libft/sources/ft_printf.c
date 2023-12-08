/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:17:12 by gbussier          #+#    #+#             */
/*   Updated: 2023/06/01 12:14:36 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int	ft_putresult(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == '%')
		count = ft_put_char('%');
	else if (type == 'c')
		count = ft_put_char(va_arg(ap, int));
	else if (type == 's')
		count = ft_put_str(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		count = ft_put_nbr(va_arg(ap, int));
	else if (type == 'u')
		count = ft_put_u(va_arg(ap, unsigned int));
	else if (type == 'x')
		count = ft_put_x(va_arg(ap, unsigned long long), "0123456789abcdef");
	else if (type == 'X')
		count = ft_put_xmaj(va_arg(ap, unsigned long long), "0123456789ABCDEF");
	else if (type == 'p')
		count = ft_put_ptr(va_arg(ap, void *), "0123456789abcdef");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list				ap;
	unsigned long		i;
	int					count;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			count = count + ft_putresult(format[i + 1], ap);
			i++;
		}
		else
			count = count + ft_put_char(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
