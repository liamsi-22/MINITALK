/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 06:12:17 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/04/19 16:46:02 by iel-fagh         ###   ########.fr       */
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

static void signal_handler(int sig, siginfo_t *info, void *ctx)
{
    static unsigned char    number;
    static int  i;

    (void)ctx;
    number |= (sig == SIGUSR1);
    i++;
    if (i == 8)
    {
        write(STDOUT_FILENO, &number, 1);
        ft_kill(info->si_pid, SIGUSR1);
        number = 0;
        i = 0;
    }
    else

        number <<= 1; 
}

int main(void)
{
    int pid;
    
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &signal_handler;
    pid = getpid();
    write(1, "Process ID is : ", 16);
    ft_putnbr(pid);
    write(1, "\n", 1);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
    pause();
    return (0);
}