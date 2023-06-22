/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:35:43 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/22 17:26:35 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_viez(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message reçu\n");
	(void)signal;
}

void	read_all(char *s, int pid)
{
	int	i;
	int	len;
	int	b;

	i = 0;
	if (!s[i])
		return ;
	signal(SIGUSR1, handle_viez);
	signal(SIGUSR2, handle_viez);
	len = ft_strlen(s);
	while (i <= len)
	{
		b = -1;
		while (++b < 8)
		{
			usleep(900);
			if ((s[i] & (1 << b)) == 0)
				kill (pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Erreur : Conversion du PID échouée\n");
		return (0);
	}
	read_all(av[2], pid);
}
