/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:29:33 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/28 22:06:24 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_sig_received;

int	char_to_bit(char c, int pid)
{
	int	i;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		i = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_sig_received == 0)
		{
			if (i == 100)
			{
				ft_printf("No signal received.\nExit.\n");
				exit(1);
			}
			i++;
			usleep(1000);
		}
		g_sig_received = 0;
		bit_index--;
	}
	return (0);
}

void	signal_handler(int signum)
{
	static int	i;

	g_sig_received = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		ft_printf("Number of bytes received : %d\n", i / 8);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;
	int					i;

	if (argc != 3)
	{
		ft_printf("You must write two arguments,");
		ft_printf(" firts the pid then your message.\nExit.\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Signal error. \n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Signal error.\n");
	i = 0;
	while (argv[2][i])
		char_to_bit(argv[2][i++], pid);
	char_to_bit('\0', pid);
	return (0);
}
