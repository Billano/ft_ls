/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:12:01 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/06 01:14:46 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;
	size_t	k;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	length = ft_strlen(little);
	while (i < len && big[i])
	{
		j = 0;
		k = i;
		while (big[i] == little[j] && big[i] && little[j] && i < len)
		{
			i++;
			j++;
		}
		if (j == length)
			return ((char *)&big[k]);
		if (j != 0)
			i = k;
		i++;
	}
	return (NULL);
}
