/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:05:21 by iel-fagh          #+#    #+#             */
/*   Updated: 2023/12/10 18:10:23 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		count = ft_putchar('-');
		return (1 + ft_putnbr(-n));
	}
	else if (n < 10)
	{
		count = ft_putchar((n % 10) + '0');
		return (count);
	}
	else
	{
		count = ft_putnbr(n / 10);
		return (count + ft_putnbr(n % 10));
	}
}
