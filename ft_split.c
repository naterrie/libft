/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 06:05:27 by naterrie          #+#    #+#             */
/*   Updated: 2022/11/15 10:03:13 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	countstr(char const *s, char c)
{
	size_t	nbstr;
	size_t	i;

	nbstr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			nbstr++;
		}
		i++;
	}
	return (nbstr);
}

const char	*dupuntilc(char **dest, char const *src, char c)
{
	size_t	len;
	size_t	i;

	while (*src == c)
		src++;
	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	*dest = (char *)malloc(sizeof(char) * (len + 1));
	if (*dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
	src += len + 1;
	return (src);
}

void	freestr(char ***str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	nbstr;

	nbstr = countstr(s, c);
	str = (char **)malloc(sizeof(char *) * (nbstr + 1));
	if (str)
	{
		str[nbstr] = NULL;
		i = 0;
		while (i < nbstr)
		{
			s = dupuntilc(str + i, s, c);
			if (s == NULL)
			{
				freestr(&str, i);
				break ;
			}
			i++;
		}
	}
	return (str);
}
