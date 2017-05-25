/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 02:21:05 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/06 22:06:26 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;
	unsigned char		p;
	size_t				i;

	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	p = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == p)
		{
			i++;
			return ((void *)(dst + i));
		}
		i++;
	}
	return (NULL);
}
