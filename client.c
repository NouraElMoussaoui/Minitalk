/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:02:48 by nel-mous          #+#    #+#             */
/*   Updated: 2023/01/14 19:35:24 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_nbr(char *number)
{
	int	d;

	d = 0;
	while (number[d])
	{
		if (!ft_isdigit(number[d]))
			return (0);
		d++;
	}
	return (1);
}

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

char	*strbinary(char *msg)
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

void	send_message(char *a, int pid)
{
	char	*s;
	int		i;
	int		signal;

	s = strbinary(a);
	i = 0;
	while (s[i])
	{
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

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (!check_nbr(av[1]))
			return (0);
		send_message(av[2], ft_atoi(av[1]));
	}
	return (0);
}
