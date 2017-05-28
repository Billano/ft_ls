/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:49:36 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/03 23:29:28 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				length;
	int				i;
	unsigned char	*p;
	char			a;

	length = 0;
	a = (unsigned char)c;
	p = (unsigned char *)s;
	while (s[length])
		length++;
	i = length;
	while (i >= 0)
	{
		if (p[i] == a)
			return ((char *)&p[i]);
		i--;
	}
	return (NULL);
}
