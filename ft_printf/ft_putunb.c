/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:22:42 by nel-mous          #+#    #+#             */
/*   Updated: 2022/12/24 09:56:32 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunb(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putunb(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (nb_digits(n, 10));
}
