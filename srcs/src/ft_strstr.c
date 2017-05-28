/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:22:04 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/03 01:27:30 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	length;
	size_t	k;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	length = ft_strlen(little);
	while (big[i])
	{
		j = 0;
		k = i;
		while (big[i] == little[j] && big[i++] && little[j++])
			;
		if (j == length)
			return ((char *)&big[k]);
		if (j != 0)
			i = k;
		i++;
	}
	return (NULL);
}
