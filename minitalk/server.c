/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:12:06 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/18 15:28:45 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	signal_handler(int signal)
{
	static int	bit_count = 0;
	static int	character = 0;

	if (signal == SIGUSR1)
	{
		character |= (1 << (7 - bit_count));
		printf("Signal SIGUSR1 reçu, bit ajouté : 1\n");
	}
	else if (signal == SIGUSR2)
	{
		printf("Signal SIGUSR2 reçu, bit ajouté : 0\n");
	}
	bit_count++;
	printf("Bits reçus : %d\n", bit_count);
	if (bit_count == 8)
	{
		printf("Caractère reconstruit : %c\n", character);
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
}

int	main(void)
{
	printf("PID du server : %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
