/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:35:20 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/22 17:25:40 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	g_rc = 0;
	static int				g_bc = 0;

	if (signal == SIGUSR1)
		g_rc |= (1 << g_bc);
	g_bc++;
	if (g_bc == 8)
	{
		if (g_rc == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		ft_printf("%c", g_rc);
		g_rc = 0;
		g_bc = 0;
	}
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
	}
	return (0);
}
