/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 04:04:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 04:04:21 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_printf_length(char *str)
{
	size_t	i;
	char	*len;

	i = 0;
	len = ft_strnew(2);
	while (str[i])
	{
		if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		{
			i++;
			len[0] = str[i - 1];
			if ((str[i - 1] == 'h' && str[i] == 'h') || (str[i - 1] == 'l' &&
				str[i] == 'l'))
			{
				len[1] = str[i];
				len[2] = '\0';
				return (len);
			}
			len[1] = '\0';
			return (len);
		}
		i++;
	}
	len[0] = '\0';
	return (len);
}
