/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:52:39 by naterrie          #+#    #+#             */
/*   Updated: 2022/11/17 19:08:31 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign(int nb)
{
	if (nb == -1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *sttr)
{
	long	i;
	long	nbr;
	int		neg;

	i = 0;
	nbr = 0;
	neg = -1;
	while ((sttr[i] <= 13 && sttr[i] >= 9) || sttr[i] == ' ')
		i++;
	if (sttr[i] != '\0' && sttr[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (sttr[i] == '+')
		i++;
	while (ft_isdigit(sttr[i]))
	{
		if (nbr != (nbr * 10) / 10)
			return (sign(neg));
		nbr = (nbr * 10) + (sttr[i++] - '0');
	}
	if (neg == 1)
		return (-nbr);
	return (nbr);
}
