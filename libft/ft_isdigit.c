/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:06:50 by nel-mous          #+#    #+#             */
/*   Updated: 2022/10/21 12:55:38 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}