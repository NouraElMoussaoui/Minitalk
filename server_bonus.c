/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 08:51:25 by nel-mous          #+#    #+#             */
/*   Updated: 2023/01/29 18:18:18 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_power(int n, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	else
		return (n * ft_power(n, p - 1));
}

char	bin_char(char *s)
{
	int	res;
	int	i;
	int	p;

	res = 0;
	i = 0;
	p = 7;
	while (s[i] && p >= 0)
	{
		res = res + (ft_power(2, p) * (s[i] - '0'));
		p--;
		i++;
	}
	return (res);
}

void	siguser_handler(int num, siginfo_t *info, void *context)
{
	static int	id;
	static int	i;
	static char	arr[9];
	char		c;

	(void)context;
	if (id != info->si_pid)
	{
		i = 0;
		id = info->si_pid;
	}
	if (num == SIGUSR1)
		arr[i] = '0';
	else
		arr[i] = '1';
	kill(info->si_pid, SIGUSR1);
	i++;
	if (i == 8)
	{
		c = bin_char(arr);
		ft_printf("%c", c);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", (int)getpid());
	sa.sa_sigaction = &siguser_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
