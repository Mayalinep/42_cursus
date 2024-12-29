/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:29:01 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/28 22:18:36 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_char(int signum, char *bit)
{
	if (signum == SIGUSR1)
		*bit = (*bit << 1) | 1;
	else if (signum == SIGUSR2)
		*bit = *bit << 1;
}

void	handle_lst(t_list **lst, char c)
{
	char	*char_ptr;
	t_list	*new_node;

	char_ptr = malloc(sizeof(char));
	if (!char_ptr)
		return ;
	*char_ptr = c;
	new_node = ft_lstnew(char_ptr);
	if (!new_node)
	{
		free(char_ptr);
		return ;
	}
	if (*lst == NULL)
		*lst = new_node;
	else
		ft_lstadd_back(lst, new_node);
}

void	display(t_list *string)
{
	while (string)
	{
		ft_printf("%c", *(char *)string->content);
		string = string->next;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int		pid;
	static int		i;
	static char		c;
	static t_list	*string;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	bit_to_char(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			display(string);
			free_lst(&string);
			write(1, "\n", 1);
			return ;
		}
		handle_lst(&string, c);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server pid :%d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Signal error. \n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Signal error.\n");
	while (1)
		pause();
	return (0);
}
