/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 08:51:56 by nel-mous          #+#    #+#             */
/*   Updated: 2023/01/14 18:36:04 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_j;

char	*char_bin(int nbr)
{
	int		i;
	char	*bin;

	bin = malloc(9 * sizeof(char));
	bin[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		bin[i] = nbr % 2 + '0';
		nbr = nbr / 2 ;
		i--;
	}
	return (bin);
}

char	*strbinary(unsigned char *msg)
{
	int		i;
	char	*binary;
	char	*tmp;
	char	*tmp_prime;

	binary = ft_strdup("");
	i = 0;
	while (msg[i])
	{
		tmp = binary;
		tmp_prime = char_bin(msg[i]);
		binary = ft_strjoin(tmp, tmp_prime);
		free(tmp);
		free(tmp_prime);
		i++;
	}
	return (binary);
}

void	send_message(unsigned char *a, int pid)
{
	char	*s;
	int		i;
	int		signal;

	s = strbinary(a);
	i = 0;
	while (s[i])
	{
		usleep(100);
		if (s[i] == '0')
			signal = SIGUSR1;
		if (s[i] == '1')
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			ft_printf("pid not found\n");
			return ;
		}
		usleep(100);
		i++;
	}
	free(s);
}

void	siguser_handler(int signum)
{
	if (signum == SIGUSR1)
		g_j++;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid_len;
	int					i;

	i = 0;
	pid_len = ft_strlen(av[1]);
	sa.sa_handler = &siguser_handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac == 3)
	{
		while (i < pid_len)
		{
			if (!ft_isdigit(av[1][i]))
			{
				ft_printf("invalid pid\n");
				return (0);
			}
			i++;
		}
		send_message((unsigned char *)av[2], ft_atoi(av[1]));
		if (g_j == (int)ft_strlen(av[2]) * 8)
			ft_printf("message received\n");
	}
	return (0);
}
