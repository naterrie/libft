/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:47:51 by naterrie          #+#    #+#             */
/*   Updated: 2022/11/25 14:13:18 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size > 0 && count >= SIZE_MAX / size)
		return (NULL);
	str = malloc((sizeof(char) * (count * size)));
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return ((void *)str);
}

int	main(void)
{
	void	*str;

	ft_calloc(0, 1);
	str = calloc(0, 1);
	return (0);
}
