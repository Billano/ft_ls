/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:34:11 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/01 20:55:52 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	const char	*psrc;
	size_t		i;

	pdst = (char *)dst;
	psrc = (const char *)src;
	i = -1;
	if (psrc < pdst)
	{
		while ((int)(--len) >= 0)
			*(pdst + len) = *(psrc + len);
	}
	else
	{
		while (++i < len)
			*(pdst + i) = *(psrc + i);
	}
	return (dst);
}
