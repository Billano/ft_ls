/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_trim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 01:57:23 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/15 15:30:38 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int				ft_specifier_printf(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
		|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == 'e' || c == 'E' || c == 'f' || c == 'F'
		|| c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'n' || c == '%')
		return (1);
	return (0);
}

char			*ft_printf_str_trim(const char *str)
{
	size_t	i;
	size_t	len;
	char	*fmt;

	i = 0;
	len = 0;
	while (!ft_specifier_printf(str[len]) && str[len])
		len++;
	fmt = ft_strnew(len + 1);
	while (i <= len)
	{
		fmt[i] = str[i];
		i++;
	}
	fmt[i] = '\0';
	return (fmt);
}
