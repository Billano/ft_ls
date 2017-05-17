/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:35:58 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/02 12:21:31 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				length;
	int				i;
	unsigned char	*p;
	char			a;

	length = 0;
	i = 0;
	a = (unsigned char)c;
	p = (unsigned char *)s;
	while (s[length])
		length++;
	while (i <= length)
	{
		if (*p++ == a)
			return ((void *)(p - 1));
		i++;
	}
	return (NULL);
}
