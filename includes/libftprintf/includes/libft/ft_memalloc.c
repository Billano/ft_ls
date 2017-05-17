/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:10:53 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/03 02:20:25 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *s;

	if ((s = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	ft_memset((void *)s, 0, size);
	return ((void *)s);
}
