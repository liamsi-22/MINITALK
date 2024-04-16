/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:14:49 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/04/15 20:05:37 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <time.h>

void    ft_kill(int pid, int sign)
{
    if (kill(pid, sign) == -1)
    {
        ft_printf("%s\n","error occured when sending signal !");
        exit(1);
    }
}

void	send_signal(int pid, char *str)
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
            usleep(1400);
            j--;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int pid;
    char *string;

    if (ac != 3)
    {
        ft_printf("wrong number of arguments you have to enter the PID & message !");
        return (1);
    }
    pid = ft_atoi(av[1]);
    string = av[2];
    if (pid <= 0)
    { 
        ft_printf("Invalid PID\n");
		return (1);
    }
    send_signal(pid, string);
    return (0);
}
