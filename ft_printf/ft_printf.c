/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:05:11 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/04/13 11:55:15 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;
	int		i;

	i = 0;
	va_start(ap, format);
	counter = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (ft_strchr("sdi%", format[i + 1]))
				counter += print_format(format[++i], ap);
		}
		else
			counter += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (counter);
}
