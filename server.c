/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:14:56 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/04/20 11:21:42 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig)
{
	static unsigned char	number;
	static int				i;

	number |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(STDOUT_FILENO, &number, 1);
		number = 0;
		i = 0;
	}
	else
		number <<= 1;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "Process ID is : ", 16);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
