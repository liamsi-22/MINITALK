/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 06:12:14 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/04/19 17:06:11 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    ft_kill(int pid, int sign)
{
    if (kill(pid, sign) == -1)
    {
        write(1, "ERROR UNVALID SIGNAL !", 22);
        exit(1);
    }
}

static void signal_handler(int sig)
{   
    if (sig == SIGUSR1)
    {
        write(1,"sent 1 Byte\n",12);
        usleep(2800);
    }
    
}

static void	send_signal(int pid, unsigned char *str)
{
    int i;
    int j;
    int bit;
    
    i = 0;
    while (str[i])
    {
        j = 7;
        while (j >= 0)
        {
            bit = str[i] >> j & 1;
            if (bit)
                ft_kill(pid, SIGUSR1);
            else
                ft_kill(pid,SIGUSR2);
            usleep(700);
            j--;
        }
		//usleep(300);
        i++;
    }
}

int main(int ac, char **av)
{
    int pid;
    unsigned char   *string;
    
    if (ac != 3)
    {
        write(1, "wrong number of arguments !", 27);
        return (1);
    }
    signal(SIGUSR1, signal_handler);
    pid = ft_atoi(av[1]);
    string = (unsigned char *)av[2];
    if (pid <= 0)
    {
        write(1, "Invalid PID\n", 12);
        return (1);
    }
    send_signal(pid, string);
    return (0);
}
