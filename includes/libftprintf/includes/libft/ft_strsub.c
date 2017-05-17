/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:56:55 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/03 21:06:33 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if ((new = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	i = start;
	while (s[i] && (i - start) < len)
	{
		new[i - start] = s[i];
		i++;
	}
	new[i - start] = '\0';
	return (new);
}
