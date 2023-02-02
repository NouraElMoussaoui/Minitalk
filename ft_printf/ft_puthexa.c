/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:08:15 by nel-mous          #+#    #+#             */
/*   Updated: 2022/12/24 09:56:08 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar(base[n]);
	}
	else
	{
		ft_puthexa(n / 16, c);
		ft_putchar(base[n % 16]);
	}
	return (nb_digits(n, 16));
}
