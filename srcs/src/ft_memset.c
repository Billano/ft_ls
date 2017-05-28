/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 02:08:59 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/01 20:56:50 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			n;
	unsigned char	p;
	char			*ptr;

	n = 0;
	p = (unsigned char)c;
	ptr = (char *)b;
	while (n < len)
	{
		ptr[n] = p;
		n++;
	}
	return (b);
}
