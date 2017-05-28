/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:39:25 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/01 21:01:44 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;
	unsigned char a;

	a = (unsigned char)c;
	p = (unsigned char *)s;
	while (n > 0)
	{
		if (*p++ == a)
			return ((void *)(p - 1));
		n--;
	}
	return (NULL);
}
