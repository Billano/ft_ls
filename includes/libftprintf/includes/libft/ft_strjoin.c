/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:08:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/04/12 02:00:07 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if ((new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) \
					+ 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < ft_strlen(s1))
			new[i] = s1[i];
		else
			new[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	new[i] = '\0';
	return (new);
}
