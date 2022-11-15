/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:13:40 by naterrie          #+#    #+#             */
/*   Updated: 2022/11/15 09:01:46 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	size(int n)
{
	long	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

int	sign(int n)
{
	if (n < 0)
		return (1);
	return (0);

}

char	*ft_itoa(int n)
{
	long	nlong;
	long	len;
	char	*str;

	nlong = n;
	len = size(nlong);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nlong < 0)
		nlong = -nlong
	while (len >= 0)
	{
		str[len] = (nlong %10) + '0';
		len--
	}
}
