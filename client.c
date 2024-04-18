/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:14:49 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/04/18 21:22:43 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <time.h>

static void    ft_kill(int pid, int sign)
{
    if (kill(pid, sign) == -1)
    {
        write(1, "ERROR UNVALID SIGNAL !", 22);
        exit(1);
    }
}

static void	send_signal(int pid, char *str)
{
    int i;
    int j;
    int bit;

    i = 0;
    while (str[i])
    {
        j = 7;
        while(j >= 0)
        {
            bit = (str[i] >> j) & 1;
            if (bit)
                ft_kill(pid, SIGUSR1);
            else
                ft_kill(pid, SIGUSR2);
            usleep(200);
            j--;
        }
		usleep(340);
        i++;
    }
}

int main(int ac, char **av)
{
    int pid;
    // unsigned char   *string;

    if (ac != 3)
    {
        write(1, "wrong number of arguments !", 27);
        return (1);
    }
    pid = ft_atoi(av[1]);
    // string = (unsigned char *)av[2];
    if (pid <= 0)
    { 
        write(1, "Invalid PID\n", 12);
		return (1);
    }
    send_signal(pid, av[2]);
    return (0);
}
